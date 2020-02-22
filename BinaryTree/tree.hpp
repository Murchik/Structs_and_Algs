#ifndef tree_hpp
#define tree_hpp

#include <iostream>

struct Node
{
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    int data;

    Node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        data = -1;
    }
    Node(int value)
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        data = value;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};

class BinTree
{
private:
    Node *root;
    int count;

public:
    BinTree()
    {
        root = nullptr;
        count = 0;
    }
    ~BinTree()
    {
        delete root;
    }

    int getCount()
    {
        return count;
    }
    Node *getRoot()
    {
        return root;
    }

    void insert(int value);
    Node *search(int key);
    void postTraversal(Node *current);
};

Node *BinTree::search(int key)
{
    Node *current;
    current = root;
    while (current != nullptr && current->data != key)
    {
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

void BinTree::postTraversal(Node *current)
{
    if (current == nullptr)
        return;
    postTraversal(current->left);
    postTraversal(current->right);
    std::cout << current->data << std::endl;
}

void BinTree::insert(int value)
{
    Node *newElement;
    Node *current;
    Node *parent;

    current = root;
    count++;
    if (current == nullptr)
    {
        newElement = new Node(value);
        root = newElement;
        return;
    }

    do
    {
        if (value > current->data)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            parent = current;
            current = current->left;
        }

    } while (current != nullptr);

    newElement = new Node(value);
    newElement->parent = parent;

    if (value < parent->data)
        parent->left = newElement;
    else
        parent->right = newElement;
}

#endif
