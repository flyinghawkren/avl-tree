#include "AVLTree.h"
#include <iostream>

void printNode(Node<int> *node) {
    if (node == 0)
        std::cout << "Node = 0" << std::endl;
    else
        std::cout << "Node[key=" << node->key << ",height=" << node->height << "]" << std::endl;
}

int main(void) {
    AVLTree<int> tree;
    tree.traverse(printNode);

    tree.insert(33);
    tree.insert(22);
    tree.insert(35);
    tree.insert(37);
    tree.insert(39);
    tree.traverse(printNode);

    Node<int>* node1 = tree.find(37);
    if (node1 == 0)
        std::cout << "Not found 37 in tree." << std::endl;
    else
        std::cout << "Found node[key=" << node1->key << ",height=" << node1->height << "]" << std::endl;

    tree.erase(33);
    tree.traverse(printNode);

    tree.destroy();
    Node<int>* node2 = tree.find(37);
    if (node2 == 0)
        std::cout << "Not found 37 in tree." << std::endl;
    else
        std::cout << "Found node[key=" << node2->key << ",height=" << node2->height << "]" << std::endl;
}