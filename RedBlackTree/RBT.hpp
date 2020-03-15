#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>

enum Color : bool { RED, BLACK };

template <typename Type>
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    Type data;
};

template <typename Type>
class RBTree {
private:
    Node* root;

    Node* traversalLNR(Node* node);

public:
    RBTree();
    ~RBTree();

    void print();
};

#include "RBT.cpp"

#endif  // RED_BLACK_TREE_HPP
