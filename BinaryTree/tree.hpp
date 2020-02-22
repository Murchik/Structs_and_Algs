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
        // INSERT YOUR CODE HERE
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
        // INSERT YOUR CODE HERE
    }

    int getCount()
    {
        return count;
    }
    Node *getRoot()
    {
        return root;
    }

    /* 
        Отмеченные (*) необходимы по варианту задания
    */

    // (*) Поиск узла с заданным значением ключа
    Node *search(int key);

    // Прямой обход (Pre-order / NLR)
    void preTraversal(Node *);

    // Симметричный (центрированный) обход дерева (In-order / LNR)
    void inTraversal(Node *);

    // (*) Обратный обход дерева (Post-order / LRN)
    void postTraversal(Node *);

    // Поиск минимального элемента в дереве (или в поддереве)
    Node *min();
    Node *min(Node *current);

    // (*) Поиск максимального элемента в дереве (или в поддереве)
    Node *max();
    Node *max(Node *current);

    // Поиск следующего за данным элементом (FIX!!!)
    Node *next(int key);

    // Поиск эл. предшествующего данному (FIX!!!)
    Node *prev(int key);

    // (*) Вставка нового узла
    void insert(int value);

    // (*) TODO: Удаление узла
    void erase(int key);
};

// ========================================================================= //

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

void BinTree::preTraversal(Node *current)
{
    if (current == nullptr)
        return;
    std::cout << current->data << " ";
    preTraversal(current->left);
    preTraversal(current->right);
}

void BinTree::inTraversal(Node *current)
{
    if (current == nullptr)
        return;
    inTraversal(current->left);
    std::cout << current->data << " ";
    inTraversal(current->right);
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
    Node *current = root;
    while (current->left != nullptr)
        current = current->left;
    return current;
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
    Node *current = root;
    while (current->right != nullptr)
        current = current->right;
    return current;
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

/* TODO: 
     Не учтён случай, когда элемента для которого
    требуется найти следующий не существует.
     Не учтён случай, когда для заданного элемента
    не существует следующего.
*/
Node *BinTree::next(int key)
{
    Node *current = search(key);
    Node *parent = current->parent;
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

/* TODO: 
     Не учтён случай, когда элемента для которого
    требуется найти предыдущий не существует.
     Не учтён случай, когда для заданного элемента
    не существует предыдущего.
*/
Node *BinTree::prev(int key)
{
    Node *current = search(key);
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

void erase(int key)
{
    // INSERT YOUR CODE HERE
}

#endif
