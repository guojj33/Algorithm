#ifndef ADAPTIVE_HUFFMAN_TREE_H
#define ADAPTIVE_HUFFMAN_TREE_H

#include <memory.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    int fre;
    char c; //only valid for leaf node
    //bool isLeaf;
    //Node* parent;
    Node* parent;
    Node* leftChild;
    Node* rightChild;

    Node(){
        fre = 0;
        c = 0;
        parent = leftChild = rightChild = NULL;
    }
};

const int CHAR_NUM = 256;
const int CHAR_LEN = 7;

class adaptiveHuffmanTree{
public:
    Node* root;
    Node* NEW;  //NEW
    bool visited[CHAR_NUM];
    map<const char, Node*> leafNodes;
    vector<Node*> nodes;

public:
    adaptiveHuffmanTree();
    string intToA(int n,int radix);
    int Atoint(string s,int radix);
    int findIndex(Node* des);
    bool updateFre(Node* des);
    bool swapSubTree(Node* root1, Node* root2);
    void printTree();
    bool updateTree(Node* des);
    string findCode(Node* des);
    bool insert(const char c, string& code);
    void decode();
    void encode();
    string getEncodeOutputFileName(string inputFilename);
    string getDecodeOutputFileName(string inputFilename);
};

#endif
