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
    

public:
    BinTree() : root(nullptr) {};
   
    ~BinTree()
    {
        delete root;
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
    void postTraversal(Node *) const;

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



#endif
