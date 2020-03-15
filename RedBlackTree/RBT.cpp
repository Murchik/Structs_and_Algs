#ifndef RED_BLACK_TREE_CPP
#define RED_BLACK_TREE_CPP

#include "RBT.hpp"

template <typename Type>
RBTree<Type>::RBTree() {
    this->root = nullptr;
}

template <typename Type>
RBTree<Type>::~RBTree() {
    delete this->root;
}

template <typename Type>
void RBTree<Type>::print() {
    traversalLNR(this->root);
}

template <typename Type>
Node *RBTree<Type>::traversalLNR(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    traversalLNR(node->left);
    std::cout << node->data << std::endl;
    traversalLNR(node->right);
}

#endif  // RED_BLACK_TREE_CPP
