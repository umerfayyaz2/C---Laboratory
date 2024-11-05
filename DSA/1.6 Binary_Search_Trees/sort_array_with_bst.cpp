#include <iostream>
using namespace std;

// Structure for a node of the BST
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
void insert(Node *&root, int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return;
    }

    if (value < root->data)
    {
        insert(root->left, value);
    }
    else
    {
        insert(root->right, value);
    }
}

// Inorder traversal to print the elements in sorted order
void inorder_traversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

// Function to delete the BST (to avoid memory leak)
void delete_bst(Node *root)
{
    if (root == nullptr)
        return;

    delete_bst(root->left);
    delete_bst(root->right);

    delete root;
}

int main()
{
    int arr[] = {10, 5, 3, 8, 15, 12, 18, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create an empty BST
    Node *root = nullptr;

    // Insert all elements into the BST
    for (int i = 0; i < n; i++)
    {
        insert(root, arr[i]);
    }

    // Print the elements in sorted order using inorder traversal
    cout << "Sorted Array: ";
    inorder_traversal(root);
    cout << endl;

    // Delete the BST to free the memory
    delete_bst(root);

    return 0;
}
