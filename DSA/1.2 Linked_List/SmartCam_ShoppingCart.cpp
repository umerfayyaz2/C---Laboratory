#include <iostream>
#include <string>
using namespace std;

// Node structure representing each product
struct ProductNode
{
    string productName;
    double productPrice;
    int quantity;
    ProductNode *prev;
    ProductNode *next;

    ProductNode(string name, double price, int qty)
        : productName(name), productPrice(price), quantity(qty), prev(nullptr), next(nullptr) {}
};

// Class representing the smart shopping cart
class SmartShoppingCart
{
    ProductNode *head;
    ProductNode *tail;
    double totalPrice;

public:
    SmartShoppingCart() : head(nullptr), tail(nullptr), totalPrice(0) {}

    // Add product to the cart
    void addProduct(string name, double price, int qty)
    {
        ProductNode *newNode = new ProductNode(name, price, qty);
        totalPrice += price * qty;

        if (!head)
        { // If the cart is empty
            head = tail = newNode;
        }
        else
        { // Append to the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Added: " << qty << " x " << name << " at $" << price << " each.\n";
        displayCart();
    }

    // Remove product from the cart
    void removeProduct(string name)
    {
        ProductNode *current = head;

        while (current)
        {
            if (current->productName == name)
            {
                totalPrice -= current->productPrice * current->quantity;

                // Remove node from the list
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                if (current == head)
                    head = current->next; // Update head if needed
                if (current == tail)
                    tail = current->prev; // Update tail if needed

                delete current;
                cout << "Removed: " << name << " from the cart.\n";
                displayCart();
                return;
            }
            current = current->next;
        }
        cout << "Product not found: " << name << endl;
    }

    // Display current cart items and total price
    void displayCart()
    {
        if (!head)
        {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "Current Cart:\n";
        ProductNode *current = head;
        while (current)
        {
            cout << current->quantity << " x " << current->productName
                 << " at $" << current->productPrice << " each\n";
            current = current->next;
        }
        cout << "Total Price: $" << totalPrice << endl;
    }

    // Calculate and display total price (real-time display simulation)
    double getTotalPrice()
    {
        return totalPrice;
    }
};

int main()
{
    SmartShoppingCart cart;

    // Simulate camera detection adding items to the cart
    cart.addProduct("Apples", 1.50, 4);
    cart.addProduct("Bread", 2.00, 2);
    cart.addProduct("Milk", 3.25, 1);

    // Simulate camera detection removing an item
    cart.removeProduct("Bread");

    // Display final cart state
    cout << "Final Total Price: $" << cart.getTotalPrice() << endl;

    return 0;
}
