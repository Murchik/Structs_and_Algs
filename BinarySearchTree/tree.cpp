#include "tree.hpp"

Node *BinTree::search(int key)
{
    Node *current = root;
    while (current != nullptr && current->data != key)
    {
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

void BinTree::preTraversal()
{
    preTraversal(root);
}

void BinTree::preTraversal(Node *current)
{
    if (current == nullptr)
        return;
    std::cout << current->data << " ";
    preTraversal(current->left);
    preTraversal(current->right);
}

void BinTree::inTraversal()
{
    inTraversal(root);
}

void BinTree::inTraversal(Node *current)
{
    if (current == nullptr)
        return;
    inTraversal(current->left);
    std::cout << current->data << " ";
    inTraversal(current->right);
}

void BinTree::postTraversal()
{
    postTraversal(root);
}

void BinTree::postTraversal(Node *current)
{
    if (current == nullptr)
        return;
    postTraversal(current->left);
    postTraversal(current->right);
    std::cout << current->data << " ";
}

Node *BinTree::min()
{
    Node *result = min(root);
    return result;
}
Node *BinTree::min(Node *current)
{
    if (current != nullptr)
    {
        while (current->left != nullptr)
            current = current->left;
    }
    return current;
}

Node *BinTree::max()
{
    Node *result = max(root);
    return result;
}
Node *BinTree::max(Node *current)
{
    if (current != nullptr)
    {
        while (current->right != nullptr)
            current = current->right;
    }
    return current;
}

Node *BinTree::next(int key)
{
    Node *current = search(key);
    Node *parent = current->parent;

    if (current == nullptr)
        return nullptr;

    if (current == max(root))
        return nullptr;

    if (current->right != nullptr)
    {
        current = min(current->right);
        return current;
    }

    if (current == parent->left)
        return parent;

    while (current != parent->left)
    {
        current = current->parent;
        parent = parent->parent;
    }
    return current->parent;
}

Node *BinTree::prev(int key)
{
    Node *current = search(key);

    if (current == nullptr)
        return nullptr;

    if (current == min(root))
        return nullptr;

    Node *parent = current->parent;
    if (current->left != nullptr)
    {
        current = max(current->left);
        return current;
    }

    if (current == parent->right)
        return parent;

    while (current != parent->right)
    {
        current = current->parent;
        parent = parent->parent;
    }
    return current->parent;
}

void BinTree::insert(int value)
{
    Node *newElement;
    Node *current;
    Node *parent;

    current = root;

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

void BinTree::transplant(Node *current, Node *swap)
{
    Node *parent = current->parent;

    if (parent == nullptr)
        root = swap;
    else
    {
        if (parent->left == current)
            parent->left = swap;
        else
            parent->right = swap;
    }
    if (swap != nullptr)
        swap->parent = parent;
}

int BinTree::erase(int key)
{
    Node *current = search(key);

    if (current == nullptr)
        return -1;

    if (current->left == nullptr)
        transplant(current, current->right);
    else
    {
        if (current->right == nullptr)
            transplant(current, current->left);
        else
        {
            Node *min = this->min(current->right);
            if (min != current->right)
            {
                transplant(min, min->right);
                min->right = current->right;
                min->right->parent = min;
            }
            transplant(current, min);
            min->left = current->left;
            min->left->parent = min;
        }
    }
    current->left = current->right = nullptr;
    delete current;
    return 0;
}
