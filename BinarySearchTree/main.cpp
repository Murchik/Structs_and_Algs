#include <iostream>
#include "tree.hpp"

int main()
{
    using namespace std;

    BinTree tree;
    Node *rez;

    tree.insert(9);
    tree.insert(11);
    tree.insert(7);
    tree.insert(8);
    tree.insert(10);
    tree.insert(6);

    if ((rez = tree.search(6)) != nullptr)
        cout << "Found element: " << rez->data << endl;
    else
        cout << "Element " << 6 << " not found" << endl;

    if ((rez = tree.search(1)) != nullptr)
        cout << "Found element: " << rez->data << endl;
    else
        cout << "Element " << 1 << " not found" << endl;

    cout << endl;

    rez = tree.getRoot();
    cout << "Tree pre-traversal here:\n ";
    tree.preTraversal(rez);
    cout << endl;

    rez = tree.getRoot();
    cout << "Tree in-traversal here:\n ";
    tree.inTraversal(rez);
    cout << endl;

    rez = tree.getRoot();
    cout << "Tree post-traversal here:\n ";
    tree.postTraversal(rez);
    cout << endl;

    cout << endl;

    rez = tree.min();
    cout << "min element: " << rez->data << endl;

    rez = tree.max();
    cout << "max element: " << rez->data << endl;

    cout << endl;

    for (int i = 7; i < 11; ++i)
    {
        rez = tree.next(i);
        cout << "next element for " << i << ": " << rez->data << endl;
        rez = tree.prev(i);
        cout << "prev element for " << i << ": " << rez->data << endl;
        cout << endl;
    }

    return 0;
}
