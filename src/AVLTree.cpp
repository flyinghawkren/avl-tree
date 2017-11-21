#include "AVLTree.h"

template<class T>
class AVLTreeImpl {
public:
    Node<T>* getRoot() {
        return _root;
    }

    void traverse(Node<T>* node, void (*traverseFunc)(Node<T> *node)) {

    }

private:
    Node<T>* _root;
};

template<class T>
AVLTree<T>::AVLTree() {
    _impl = new AVLTreeImpl<T>();
}

template<class T>
AVLTree<T>::~AVLTree() {
    
}

template<class T>
void AVLTree<T>::insert(T key) {
    
}

template<class T>
void AVLTree<T>::erase(T key) {
    
}

template<class T>
Node<T>* AVLTree<T>::find(T key) {
    
}

template<class T>
void AVLTree<T>::traverse(void (*traverseFunc)(Node<T> *node)) {
    _impl->traverse(_impl->getRoot(), traverseFunc);
}

template class AVLTree<int>;