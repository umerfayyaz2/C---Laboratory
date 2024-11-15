#include <iostream>
#include <string>
using namespace std;

// Class representing a product node in the binary tree
class ProductNode
{
public:
    string name;        // Name of the product
    int stock;          // Stock quantity
    ProductNode *left;  // Left child (lower stock)
    ProductNode *right; // Right child (higher stock)

    ProductNode(string productName, int stockQty)
        : name(productName), stock(stockQty), left(nullptr), right(nullptr) {}
};

// Class for the Grocery Restocking System
class GroceryRestockingSystem
{
private:
    ProductNode *root; // Root of the binary tree

    // Helper function to add a product to the binary tree
    ProductNode *addProduct(ProductNode *node, string name, int stock)
    {
        if (node == nullptr)
        {
            return new ProductNode(name, stock);
        }
        if (stock < node->stock)
        {
            node->left = addProduct(node->left, name, stock);
        }
        else
        {
            node->right = addProduct(node->right, name, stock);
        }
        return node;
    }

    // Helper function to traverse the tree and identify products that need restocking
    void findLowStockProducts(ProductNode *node, int threshold, vector<string> &lowStockProducts)
    {
        if (node == nullptr)
            return;

        // Check current product's stock
        if (node->stock < threshold)
        {
            lowStockProducts.push_back(node->name + " (Stock: " + to_string(node->stock) + ")");
        }

        // Traverse left and right subtrees
        findLowStockProducts(node->left, threshold, lowStockProducts);
        findLowStockProducts(node->right, threshold, lowStockProducts);
    }

    // Helper function for in-order traversal to display products
    void displayProducts(ProductNode *node)
    {
        if (node == nullptr)
            return;
        displayProducts(node->left);
        cout << "Product: " << node->name << ", Stock: " << node->stock << endl;
        displayProducts(node->right);
    }

public:
    // Constructor initializes an empty tree
    GroceryRestockingSystem() : root(nullptr) {}

    // Add a product to the system
    void addProduct(string name, int stock)
    {
        root = addProduct(root, name, stock);
    }

    // Find products with stock below the threshold
    void findLowStockProducts(int threshold)
    {
        vector<string> lowStockProducts;
        findLowStockProducts(root, threshold, lowStockProducts);

        cout << "Products needing restocking (Threshold: " << threshold << "):" << endl;
        if (lowStockProducts.empty())
        {
            cout << "All products are adequately stocked!" << endl;
        }
        else
        {
            for (const string &product : lowStockProducts)
            {
                cout << product << endl;
            }
        }
    }

    // Display all products in the system
    void displayProducts()
    {
        cout << "Current inventory:" << endl;
        displayProducts(root);
    }
};

int main()
{
    // Initialize the grocery restocking system
    GroceryRestockingSystem system;

    // Add products
    system.addProduct("Apples", 50);
    system.addProduct("Bananas", 30);
    system.addProduct("Oranges", 10);
    system.addProduct("Tomatoes", 5);
    system.addProduct("Carrots", 25);
    system.addProduct("Potatoes", 100);

    // Display all products
    system.displayProducts();

    // Find and display products that need restocking (threshold = 20)
    system.findLowStockProducts(20);

    return 0;
}
