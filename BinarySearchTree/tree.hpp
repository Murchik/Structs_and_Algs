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
        ���������� (*) ���������� �� �������� �������
    */

    // (*) ����� ���� � �������� ��������� �����
    Node *search(int key);

    // ������ ����� (Pre-order / NLR)
    void preTraversal();
    void preTraversal(Node *);

    // ������������ (��������������) ����� ������ (In-order / LNR)
    void inTraversal();
    void inTraversal(Node *);

    // (*) �������� ����� ������ (Post-order / LRN)
    void postTraversal();
    void postTraversal(Node *);

    // ����� ������������ �������� � ������ (��� � ���������)
    Node *min();
    Node *min(Node *current);

    // (*) ����� ������������� �������� � ������ (��� � ���������)
    Node *max();
    Node *max(Node *current);

    // ����� ���������� �� ������ ���������
    Node *next(int key);

    // ����� ��. ��������������� �������
    Node *prev(int key);

    // (*) ������� ������ ����
    void insert(int value);

    // (*) �������� ����
    int erase(int key);
};

#endif
