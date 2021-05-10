#include <iostream>
#include <fstream>
#include "adaptiveHuffmanTree.h"
using namespace std;

int main(){
    adaptiveHuffmanTree tree;
    cout << "[Adaptive Huffman Coding Decoder]\n";
    tree.decode();
    cout << "Decode complete.\n";
}