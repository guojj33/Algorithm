#include <iostream>
#include <vector>
using namespace std;

struct node {
  node* leftChild;
  node* rightChild;
  int data;

  node() {
    this->leftChild = NULL;
    this->rightChild = NULL;
    data = -1;
  }
};

typedef node *biTree;

// 递归构建二叉树
biTree preInitTree() {
  biTree T;
  if(cin.peek() == '\n') {  // 已读到行末，停止构建树
    return NULL;
  }
  int d;
  cin >> d;
  if(d == -1) { // 表示空结点
    return NULL;
  }
  else {  // 当结点为非空时，才继续构建其左右子树
    T = new node();
    T->data = d;
    T->leftChild = preInitTree(); // 递归构建左子树
    T->rightChild = preInitTree();  // 递归构建右子树
  }
}

void preOrder(biTree root) { // 先序遍历
  if(root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->leftChild);
  preOrder(root->rightChild);
  return;
}

void inOrder(biTree root) { // 中序遍历
  if(root == NULL) {
    return;
  }
  inOrder(root->leftChild);
  cout << root->data << " ";
  inOrder(root->rightChild);
  return;
}

void postOrder(biTree root) {// 后序遍历
  if(root == NULL) {
    return;
  }
  postOrder(root->leftChild);
  postOrder(root->rightChild);
  cout << root->data << " ";
}

int find(vector<node*>* path, node* cur, int d){
  if (cur == NULL) {  // cur 为空时返回失败
    return 0;
  }

  path->push_back(cur);  // cur 非空，加入 path
  if(cur->data == d) { // cur 即要找的结点，返回成功
    return 1;
  }

  int lResult = find(path, cur->leftChild, d);
  int rResult = find(path, cur->rightChild, d);
  if (lResult == 1 || rResult == 1){  // 若左右孩子递归结果为成功，则此时 path 已包含完整路径，返回成功
    return 1;
  }
  else {      // 若左右孩子递归结果都为失败，说明经过 cur 结点抵达不了目标，将 cur 从 path 中删除
    path->pop_back();
    return 0;
  }
}

vector<node*>* findPath(biTree root, int d) {
  vector<node*>* path = new vector<node*>();
  find(path, root, d);
  return path;
}

// 0 1 -1 2 4 -1 -1 -1 3 5 -1 -1 -1
int main() {
  cout <<"输入一个包含空孩子信息的先序序列以构建树\n";
  cout << "(空孩子用-1表示， 如 0 1 -1 -1 2 -1 -1 表示根节点为 0，做孩子为 1，右孩子为 2):\n";
  biTree root = preInitTree();
  cout << "preOrder:\n";
  preOrder(root);
  cout << "\n";
  cout << "inOrder:\n";
  inOrder(root);
  cout << "\n";
  cout << "postOrder:\n";
  postOrder(root);
  cout << "\n";
  while(true) {
    cout << "输入要寻找的结点\n";
    int d;
    cin >> d;
    if(d == -1) {
      break;
    }
    vector<node*> path = *findPath(root, d);
    cout << "path:\n";
    for(int i = 0; i < path.size(); ++i) {
      cout << path[i]->data << " ";
    }
    cout << "\n";
  }
}