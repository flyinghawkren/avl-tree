#include "AVLTree.h"
#include <algorithm>

template<class T>
class AVLTreeImpl {
    Node<T>* _root;

public:
    AVLTreeImpl() : _root(0) {}
    ~AVLTreeImpl() { destroy(); }

    Node<T>* getRoot() {
        return _root;
    }

    int getHeight() { return getHeight(_root); }
    int getBalance() { return getBalance(_root); }

    void insert(const T& key) {
        _root = insertImpl(_root, key);
    }

    void erase(const T& key) {
        _root = eraseImpl(_root, key);
    }

    const Node<T>* find(const T& key) const {
        return findImpl(_root, key);
    }

    void traverse(Node<T>* node, void (*traverseFunc)(Node<T> *node)) {
        if (node == 0)
            return;

        traverse(node->left, traverseFunc);
        traverseFunc(node);
        traverse(node->right, traverseFunc);
    }

    void destroy() {
        destroy(_root);
        _root = 0;
    }

private:
    int getHeight(Node<T>* node) {
        return node == 0 ? 0 : node->height;
    }

    int getBalance(Node<T>* node) {
        return node == 0 ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    Node<T>* ll_rotate(Node<T>* node) {
        Node<T>* temp = node->left;
        node->left = temp->right;
        temp->right = node;

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;
        return temp;
    }

    Node<T>* rr_rotate(Node<T>* node) {
        Node<T>* temp = node->right;
        node->right = temp->left;
        temp->left = node;

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;
        return temp;
    }

    Node<T>* lr_rotate(Node<T>* node) {
        Node<T>* temp = node->left;
        node->left = rr_rotate(temp);
        return ll_rotate(node);
    }

    Node<T>* rl_rotate(Node<T>* node) {
        Node<T>* temp = node->right;
        node->right = ll_rotate(temp);
        return rr_rotate(node);
    }

    const Node<T>* findImpl(Node<T>* node, const T& key) const {
        if (node == 0)
            return node;

        if (key < node->key)
            return findImpl(node->left, key);
        else if (key > node->key)
            return findImpl(node->right, key);
        else
            return node;
    }

    Node<T>* insertImpl(Node<T>* node, const T& key) {
        if (node == 0)
            return new Node<T>(key);

        if (key < node->key)
            node->left = insertImpl(node->left, key);
        else if (key > node->key)
            node->right = insertImpl(node->right, key);
        else
            return node;

        return rebalance(node);
    }

    Node<T>* eraseImpl(Node<T>* node, const T& key) {
        if (node == 0)
            return 0;

        if (key < node->key)
            node->left = eraseImpl(node->left, key);
        else if (key > node->key)
            node->right = eraseImpl(node->right, key);
        else {
            if (node->left && node->right) {
                Node<T>* temp = node->right;
                while (temp->left)
                    temp = temp->left;
                
                node->key = temp->key;
                node->right = eraseImpl(node->right, temp->key);
            }
            else {
                Node<T>* temp = node;
                node = (node->left != 0 ? node->left : node->right);
                delete temp;
            }
        }

        return rebalance(node);
    }

    Node<T>* rebalance(Node<T> *node) {
        if (node == 0)
            return node;

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) > 0)
            return ll_rotate(node);
        else if (balance > 1 && getBalance(node->left) < 0)
            return lr_rotate(node);
        else if (balance < -1 && getBalance(node->right) > 0)
            return rl_rotate(node);
        else if (balance < -1 && getBalance(node->right) < 0)
            return rr_rotate(node);

        return node;
    }

    void destroy(Node<T> *node) {
        if (node == 0)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};

template<class T>
AVLTree<T>::AVLTree() {
    _impl = new AVLTreeImpl<T>();
}

template<class T>
AVLTree<T>::~AVLTree() {
    if (_impl != 0)
        delete _impl;
    _impl = 0;
}

template<class T>
void AVLTree<T>::insert(const T& key) {
    _impl->insert(key);
}

template<class T>
void AVLTree<T>::erase(const T& key) {
    _impl->erase(key);
}

template<class T>
const Node<T>* AVLTree<T>::find(const T& key) const {
    return _impl->find(key);
}

template<class T>
void AVLTree<T>::destroy() {
    _impl->destroy();
}

template<class T>
void AVLTree<T>::traverse(void (*traverseFunc)(Node<T> *node)) {
    _impl->traverse(_impl->getRoot(), traverseFunc);
}

template class AVLTree<int>;