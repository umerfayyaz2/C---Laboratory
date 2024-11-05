#include <iostream>
using namespace std;

// Node structure definition
template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;

    // Constructor for convenience
    nodeType(elemType val) : info(val), lLink(nullptr), rLink(nullptr) {}
};

// Binary Tree Class Definition
template <class elemType>
class BinaryTree
{
private:
    nodeType<elemType> *root;

    // Helper function for in-order traversal
    void inOrderTraversal(nodeType<elemType> *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->lLink);
            cout << node->info << " ";
            inOrderTraversal(node->rLink);
        }
    }

    // Helper function to insert a node
    nodeType<elemType> *insertNode(nodeType<elemType> *node, elemType value)
    {
        if (node == nullptr)
        {
            return new nodeType<elemType>(value); // Create new node if position is empty
        }

        if (value < node->info)
        {
            node->lLink = insertNode(node->lLink, value); // Insert in left subtree
        }
        else
        {
            node->rLink = insertNode(node->rLink, value); // Insert in right subtree
        }
        return node;
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Insert a value in the binary tree
    void insert(elemType value)
    {
        root = insertNode(root, value);
    }

    // Perform in-order traversal
    void inOrderTraversal()
    {
        inOrderTraversal(root);
        cout << endl;
    }

    // Destructor to clean up nodes
    ~BinaryTree()
    {
        // Recursively delete all nodes (function can be implemented here if desired)
    }
};

// Main function
int main()
{
    BinaryTree<int> tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Perform in-order traversal
    cout << "In-order Traversal of Binary Tree: ";
    tree.inOrderTraversal();

    return 0;
}
