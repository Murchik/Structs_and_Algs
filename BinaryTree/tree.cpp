#include <iostream>

struct Node
{
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    struct Node *parent = nullptr;
    int data;

    ~Node()
    {
        delete left;
        delete right;
    }
};

class BinTree
{
private:
    struct Node *root;

public:
    BinTree()
    {
        root = nullptr;
    }

    ~BinTree()
    {
        delete root;
    }

    void insert(int value)
    {
        struct Node *newElement;
        struct Node *current;
        struct Node *parent;

        current = root;
        if (current == nullptr)
        {
            newElement = new Node;
            newElement->data = value;
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
        newElement = new Node;
        newElement->parent = parent;
        newElement->data = value;
        if (value < parent->data)
            parent->left = newElement;
        else
            parent->right = newElement;
    }

    struct Node *search(int key)
    {
        struct Node *current;
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
};

int main()
{
    BinTree tree;
    struct Node *rez;

    tree.insert(9);
    tree.insert(11);
    tree.insert(7);
    tree.insert(8);
    tree.insert(10);
    tree.insert(6);
    
    if((rez = tree.search(6)) != nullptr)
        std::cout << "Found element: " << rez->data << std::endl;
    else
        std::cout << "Element " << 6 << " not found" << std::endl;
    
    if((rez = tree.search(1)) != nullptr)
        std::cout << "Found element: " << rez->data << std::endl;
    else
        std::cout << "Element " << 1 << " not found" << std::endl;
    
    return 0;
}