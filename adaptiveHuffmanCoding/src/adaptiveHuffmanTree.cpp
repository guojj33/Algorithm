#include "adaptiveHuffmanTree.h"

adaptiveHuffmanTree::adaptiveHuffmanTree(){
        memset(visited, 0, CHAR_NUM*sizeof(bool));
        NEW = new Node();
        root = new Node();
        root->leftChild = NEW;
        NEW->parent = root;
        nodes.push_back(root);
    }

int adaptiveHuffmanTree::findIndex(Node* des){
    if(des == NULL)
        return -1;
    for(int i = nodes.size()-1; i >= 0; --i){
        if(nodes[i] == des)
            return i;
    }
    return -1;
}

bool adaptiveHuffmanTree::updateFre(Node* des){
    Node* cur = des;
    if(cur == NULL)
        return false;
    while(true){
        if(cur->parent == NULL)
            break;
        Node* parent = cur->parent;
        parent->fre = parent->leftChild->fre + parent->rightChild->fre;
        cur = parent;
    }
    return true;
}

bool adaptiveHuffmanTree::swapSubTree(Node* root1, Node* root2){
    //update data of node
    //cout << "same parent: " << (root1->parent == root2->parent) << "\n";
    if(root1->parent == root2->parent){ //have the same parent
        Node* parent = root1->parent;
        if(parent->leftChild == root1){
            parent->leftChild = root2;
            parent->rightChild = root1;
        }
        else if(parent->rightChild == root1){
            parent->leftChild = root1;
            parent->rightChild = root2;
        }
    }
    else{                               //have different parents
        if(root1->parent->leftChild == root1){
            root1->parent->leftChild = root2;//
        }
        else if(root1->parent->rightChild == root1){
            root1->parent->rightChild = root2;//
        }
        if(root2->parent->leftChild == root2){
            root2->parent->leftChild = root1;//
        }
        else if(root2->parent->rightChild == root2){
            root2->parent->rightChild = root1;//
        }
        Node* tmp = root1->parent;
        root1->parent = root2->parent;
        root2->parent = tmp;
    }
    return true;
}

void adaptiveHuffmanTree::printTree(){
    cout << "nodes: ";
    for(int i = 0; i < nodes.size(); ++i){
        cout << nodes[i]->fre;
        cout << "(" << (nodes[i]->leftChild == NULL ? 0 : nodes[i]->leftChild->fre) << " " << (nodes[i]->rightChild == NULL ? 0 : nodes[i]->rightChild->fre) << ")";
        if(nodes[i]->c != 0){
            cout << "(" << nodes[i]->c << ")";
        }
        cout << " ";
    }
    cout << "\n\n";
}

bool adaptiveHuffmanTree::updateTree(Node* des){   //update the tree according to the destination leaf
    Node* cur = des;
    //update the frequency
    updateFre(cur);
    //do swap if needed
    int curIndex = findIndex(des);
    while(curIndex >= 0){
        //cout << "curIndex: " << curIndex << " ";
        int toSwap = -1;
        //find the index to swap with the curIndex
        for(int i = curIndex-1; i > 0; --i){
            if(nodes[i]->fre < nodes[curIndex]->fre && nodes[i-1]->fre > nodes[curIndex]->fre){
                toSwap = i;
                break;
            }
        }
        //cout << "toSwap: " << toSwap << "\n";
        if(toSwap > 0){
            Node* tmp = nodes[curIndex];
            nodes[curIndex] = nodes[toSwap];
            nodes[toSwap] = tmp;
            swapSubTree(nodes[curIndex], nodes[toSwap]);
            updateFre(nodes[toSwap]);
            updateFre(nodes[curIndex]);
            //printTree();
        }
        curIndex = findIndex(nodes[curIndex]->parent);
    }
}

string adaptiveHuffmanTree::findCode(Node* des){     //find the code leads to the leaf node
    string result = "";
    Node* cur = des;
    while(true){
        Node* parent = cur->parent;
        if(parent == NULL)  //which indicates that cur is the root
            break;
        if(cur == parent->leftChild){
            result = "0" + result;
        }
        else if(cur == parent->rightChild){
            result = "1" + result;
        }
        cur = parent;
    }
    return result;
}

string adaptiveHuffmanTree::intToA(int n,int radix){    //n是给定radix进制的整数
    string ans = "";
    do{
        int t = n % radix;
        if(t >= 0 && t <= 9)
            ans += t + '0';
        else ans += t - 10 + 'a';
        n /= radix;
    } while(n != 0);
    reverse(ans.begin(), ans.end());
    int size = ans.size();
    for(int i = 0; i < CHAR_LEN - size; ++i){
        ans = "0" + ans;
    }
    return ans;
}

bool adaptiveHuffmanTree::insert(const char c, string& code){
    Node* des = NULL;
    string codeOfNew = findCode(NEW);
    if(visited[c] == false){
        Node* newLeaf = new Node();
        des = newLeaf;
        leafNodes.insert(pair<const char, Node*>(c, newLeaf));
        newLeaf->c = c;
        newLeaf->fre = 1;
        Node* parentOfNew = NEW->parent;
        if(parentOfNew->rightChild != NULL){
            Node* newParent = new Node();
            newParent->leftChild = NEW;
            newParent->rightChild = newLeaf;
            newParent->fre = newParent->leftChild->fre + newParent->rightChild->fre;
            newParent->parent = parentOfNew;
            parentOfNew->leftChild = newParent;
            newLeaf->parent = newParent;
            NEW->parent = newParent;
            //update the vector nodes
            nodes.push_back(newParent);
            nodes.push_back(newLeaf);
        }
        else{
            parentOfNew->rightChild = newLeaf;
            newLeaf->parent = parentOfNew;
            nodes.push_back(newLeaf);
        }
    }
    else{
        des = leafNodes.at(c);
        des->fre += 1;
    }
    if(visited[c] == false){
        code = codeOfNew + intToA((int)c, 2);
        //cout << "NEW: " << codeOfNew << "\n";
    }
    else{
        code = findCode(des);
    }
    //cout << "output: " << code << "\n\n";
    updateTree(des);
    //printTree();
    visited[c] = true;
    return true;
}

int adaptiveHuffmanTree::Atoint(string s,int radix){    //s是给定radix进制的字符串
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        char t = s[i];
        if(t >= '0' && t <= '9')
            ans = ans * radix + t - '0';
        else ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}

string adaptiveHuffmanTree::getEncodeOutputFileName(string inputFileName){
    string result = "";
    int dotIndex = 0;
    for(int i = inputFileName.size() - 1; i >= 0; --i){
        if(inputFileName[i] == '.'){
            dotIndex = i;
            break;
        }
    }
    result += inputFileName.substr(0, dotIndex);
    result += ".ahc";
    if(result[0] == '\'')
        result = result.substr(1, result.size()-1);
    return result;
}

void adaptiveHuffmanTree::encode(){
    //get input file name
    string inputFileName = "";
    cout << "Input file(.txt) name to encode: \n";
    cin >> inputFileName;
    fstream in(inputFileName);
    
    //get output file name
    string outputFileName = getEncodeOutputFileName(inputFileName);
    cout << outputFileName << "\n";
    fstream out(outputFileName, ios::binary | ios::out);

    string result = ""; //store all the code

    //sacn all char in the file and encode
    char c;
    while(in.peek() != EOF){
        c = in.get();
        string code;
        int a = c;
        insert(c, code);
        result += code;
    }

    //write the code len(bit)
    unsigned long long bitLen = result.size();
    out.write((char*)&bitLen, sizeof(unsigned long long));

    unsigned long long outputFileLen = result.size() / 8 + 1;
    char* bitmap = new char[outputFileLen];
    memset(bitmap, 0, outputFileLen*sizeof(char));
    for(int i = 0; i < result.size(); ++i){
        int tmp = result[i] - '0';
        bitmap[i / 8] |= (tmp << (i % 8));
    }
    out.write(bitmap, outputFileLen*sizeof(char));

    in.close();
    out.close();
}

string adaptiveHuffmanTree::getDecodeOutputFileName(string inputFileName){
    string result = "";
    int dotIndex = 0;
    for(int i = inputFileName.size() - 1; i >= 0; --i){
        if(inputFileName[i] == '.'){
            dotIndex = i;
            break;
        }
    }
    result += inputFileName.substr(0, dotIndex);
    result += "_decoded.txt";
    if(result[0] == '\'')
        result = result.substr(1, result.size()-1);
    return result;
}

void adaptiveHuffmanTree::decode(){
    //get input file name
    string inputFileName = "";
    cout << "Input file(.ahc) name to decode: \n";
    cin >> inputFileName;
    fstream in(inputFileName, ios::binary | ios::in);

    //get output file name
    string outputFileName = getDecodeOutputFileName(inputFileName);
    cout << outputFileName << "\n";
    fstream out(outputFileName, ios::out);

    //get code len(byte)
    in.seekg(0, in.end);
    unsigned long long inputFileLen = in.tellg();
    inputFileLen -= sizeof(unsigned long long);
    in.seekg(0, in.beg);

    //get code len(bit)
    unsigned long long bitLen;
    in.read((char*)&bitLen, sizeof(unsigned long long));

    //read all the code
    char* encode = new char[inputFileLen];
    memset(encode, 0, inputFileLen*sizeof(char));
    in.read(encode, inputFileLen*sizeof(char));

    //decode the code
    int readIndex = 0;
    while(readIndex < bitLen){
        int input;
        Node* cur = root;
        //traverse until cur is a leaf node 
        while(readIndex < bitLen){
            input = ((encode[readIndex/8] >> (readIndex%8)) & 1);
            readIndex ++;
            if(input == 0)
                cur = cur->leftChild;
            else if(input == 1)
                cur = cur->rightChild;
            if(cur == NULL){
                cout << "error!\n";
                return;
            }
            if(cur->leftChild == NULL && cur->rightChild == NULL)
                break;
        }
        
        if(cur == NEW){ //the char appears for the first time
            string s;
            for(int i = 0; i < CHAR_LEN; ++i){  //get 7 bit ASCII
                int tmp = ((encode[readIndex/8] >> (readIndex%8)) & 1);
                readIndex ++;
                s.append(to_string(tmp));
            }
            char c = Atoint(s, 2);
            out << c;
            string code;
            insert(c, code);
        }
        else{   //the char has appeared before
            out << cur->c;
            string code;
            insert(cur->c, code);
        }
    }

    in.close();
    out.close();
}
