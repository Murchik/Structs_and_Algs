#include <iostream>
#include <vector>

using namespace std;

struct Node
{

	
    Node *left=nullptr;
    Node *right=nullptr;
    Node *parent= nullptr;
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
    Node *root;
	int count;
public:
	BinTree() 
	{
		root = nullptr;
		count = 0;
	}
	
	int GetCount()
	{
		return count;
	}
	Node* GetRoot() 
	{
		return root;
	}
    ~BinTree()
    {
        delete root;
    }
	
    void insert(int value)
    {
        Node *newElement;
        Node *current;
        Node *parent;
        current = root;
		count++;
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

    Node *search(int key)
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
	
	

	void PostTraversal(Node *current)
	{
		
		if (current == nullptr) 
		{
			
			return;
		}
		
		PostTraversal(current->left);
		
		PostTraversal(current->right);
		cout << current->data << endl;
		
	}

};

int main()
{
	using Node = struct Node;
    BinTree tree;
    Node *rez;
	vector<int> List;

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
	
   

	auto localRoot = tree.GetRoot();
	cout << endl << "Tree traversal here:" << endl;
	tree.PostTraversal(localRoot);
	return 0;
	//for (auto i : Sorted) std::cout << i << " ";
}