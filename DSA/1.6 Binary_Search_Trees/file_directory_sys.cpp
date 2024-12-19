#include <iostream>
#include <string>
using namespace std;

// Class to represent a File/Directory
class FileSystemNode
{
public:
    string name;           // Name of the file or directory
    FileSystemNode *left;  // Pointer to left child (subdirectory or file)
    FileSystemNode *right; // Pointer to right child (another subdirectory or file)

    // Constructor to initialize a file/directory node
    FileSystemNode(string name) : name(name), left(nullptr), right(nullptr) {}
};

// Class to represent the File System
class FileSystem
{
private:
    FileSystemNode *root; // Root of the file system (top-level directory)

    // Recursive function to traverse and display the file system
    void displayFileSystem(FileSystemNode *node, int level)
    {
        if (node == nullptr)
            return;

        // Print spaces for tree indentation
        for (int i = 0; i < level; ++i)
            cout << "  ";
        cout << node->name << endl;

        // Recursively display subdirectories/files
        displayFileSystem(node->left, level + 1);
        displayFileSystem(node->right, level + 1);
    }

public:
    // Constructor to initialize the file system
    FileSystem() : root(nullptr) {}

    // Add a new file or directory under a parent directory (binary tree insertion)
    void addFileOrDirectory(string parentName, string name)
    {
        // If the file system is empty, make the first node as root
        if (root == nullptr)
        {
            root = new FileSystemNode(name);
            cout << "Root directory '" << name << "' created." << endl;
            return;
        }

        // Otherwise, find the parent node and add the new node as a child
        FileSystemNode *parentNode = findNode(root, parentName);
        if (parentNode != nullptr)
        {
            if (parentNode->left == nullptr)
                parentNode->left = new FileSystemNode(name);
            else if (parentNode->right == nullptr)
                parentNode->right = new FileSystemNode(name);
            else
                cout << "Parent directory already has two children." << endl;
        }
        else
        {
            cout << "Parent directory not found." << endl;
        }
    }

    // Function to find a node with the given name
    FileSystemNode *findNode(FileSystemNode *node, string name)
    {
        if (node == nullptr)
            return nullptr;
        if (node->name == name)
            return node;

        // Recursively search in left and right children
        FileSystemNode *foundNode = findNode(node->left, name);
        if (foundNode != nullptr)
            return foundNode;

        return findNode(node->right, name);
    }

    // Display the entire file system (tree)
    void display()
    {
        if (root == nullptr)
        {
            cout << "File system is empty." << endl;
        }
        else
        {
            cout << "File System Structure:" << endl;
            displayFileSystem(root, 0);
        }
    }
};

int main()
{
    // Create a FileSystem object
    FileSystem fs;

    // Add some directories and files
    fs.addFileOrDirectory("root", "Documents");
    fs.addFileOrDirectory("root", "Pictures");
    fs.addFileOrDirectory("Documents", "Resume.txt");
    fs.addFileOrDirectory("Documents", "CoverLetter.txt");
    fs.addFileOrDirectory("Pictures", "Vacation.jpg");

    // Display the file system structure
    fs.display();

    return 0;
}
