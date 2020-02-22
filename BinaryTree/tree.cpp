#include <iostream>
#include <vector>

#include "tree.hpp"

int main()
{
    using namespace std;
    using Node = struct Node;

    BinTree tree;
    Node *rez;
    vector<int> List; // ??

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

    Node *localRoot = tree.getRoot();
    cout << endl
         << "Tree traversal here:" << endl;
    tree.postTraversal(localRoot);

    return 0;
    //for (auto i : Sorted) cout << i << " ";
}