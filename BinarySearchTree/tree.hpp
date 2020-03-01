#ifndef tree_hpp
#define tree_hpp

#include <iostream>

struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    int data;

    Node()
    {
        left = right = parent = nullptr;
        data = -1;
    }

    Node(int value)
    {
        left = right = parent = nullptr;
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

    void transplant(Node *current, Node *swap);

public:
    BinTree() : root(nullptr){};

    ~BinTree() { delete root; }

    bool isCreated()
    {
        if (root != nullptr)
            return true;
        else
            return false;
    }

    /* 
        Отмеченные (*) необходимы по варианту задания
    */

    // (*) Поиск узла с заданным значением ключа
    Node *search(int key);

    // Прямой обход (Pre-order / NLR)
    void preTraversal();
    void preTraversal(Node *);

    // Симметричный (центрированный) обход дерева (In-order / LNR)
    void inTraversal();
    void inTraversal(Node *);

    // (*) Обратный обход дерева (Post-order / LRN)
    void postTraversal();
    void postTraversal(Node *);

    // Поиск минимального элемента в дереве (или в поддереве)
    Node *min();
    Node *min(Node *current);

    // (*) Поиск максимального элемента в дереве (или в поддереве)
    Node *max();
    Node *max(Node *current);

    // Поиск следующего за данным элементом
    Node *next(int key);

    // Поиск эл. предшествующего данному
    Node *prev(int key);

    // (*) Вставка нового узла
    void insert(int value);

    // (*) Удаление узла
    int erase(int key);
};

#endif
