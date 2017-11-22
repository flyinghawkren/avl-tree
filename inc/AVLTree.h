#pragma once

template<class T>
struct Node {
    T   key;

    Node* left;
    Node* right;
    int   height;

    Node(const T& key) {
        this->key = key;
        this->left = this->right = 0;
        this->height = 1;
    }
};

template<class T> class AVLTreeImpl;

template<class T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(const T& key);
    void erase(const T& key);
    Node<T>* find(const T& key) const;
    void destroy();

    void traverse(void (*traverseFunc)(Node<T> *node));

private:
    AVLTreeImpl<T> *_impl;
};