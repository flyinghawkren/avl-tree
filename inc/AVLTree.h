#pragma once

template<class T>
struct Node {
    T   key;

    Node* left;
    Node* right;
    int   height;

    Node(T key) {
        this->key = key;
        this->left = this->right = 0;
        this->height = 0;
    }
};

template<class T> class AVLTreeImpl;

template<class T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(T key);
    void erase(T key);
    Node<T>* find(T key);

    void traverse(void (*traverseFunc)(Node<T> *node));

private:
    AVLTreeImpl<T> *_impl;
};