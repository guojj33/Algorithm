#include <iostream>
#include <fstream>
#include "adaptiveHuffmanTree.h"
using namespace std;

int main(){
    adaptiveHuffmanTree tree;
    cout << "[Adaptive Huffman Coding Encoder]\n";
    tree.encode();
    cout << "Encode complete.\n";
}