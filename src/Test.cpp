#include "AVLTree.h"
#include <iostream>

void printNode(Node<int> *node) {
    if (node == 0)
        std::cout << "Node = 0" << std::endl;
    else
        std::cout << "Node[key=" << node->key << ",height=" << node->height << std::endl;
}

int main(void) {
    AVLTree<int> tree;
    tree.traverse(printNode);
}