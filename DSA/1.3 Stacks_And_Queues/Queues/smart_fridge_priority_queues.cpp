#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <string>
using namespace std;

// Struct for item details
struct Item
{
    string name;
    string type;
    int daysToExpire;
    int quantity;

    Item(string n, string t, int d, int q) : name(n), type(t), daysToExpire(d), quantity(q) {}

    // Overload operator for priority queue (sooner expiration has higher priority)
    bool operator<(const Item &other) const
    {
        return daysToExpire > other.daysToExpire;
    }
};

// Smart Fridge class
class SmartFridge
{
    unordered_map<string, Item> itemMap; // Hash table for items
    priority_queue<Item> expiryQueue;    // Priority queue for expiring items
    list<string> groceryHistory;         // Linked list for grocery history

public:
    // Add item to the fridge
    void addItem(string name, string type, int daysToExpire, int quantity)
    {
        itemMap[name] = Item(name, type, daysToExpire, quantity);
        expiryQueue.push(item);
        groceryHistory.push_back(name);
        cout << "Added: " << name << " (" << quantity << ") to the fridge.\n";
    }

    // Remove item from the fridge
    void removeItem(string name)
    {
        if (itemMap.find(name) != itemMap.end())
        {
            itemMap.erase(name);
            cout << "Removed: " << name << " from the fridge.\n";
        }
        else
        {
            cout << "Item not found: " << name << endl;
        }
    }

    // Check alerts for expiring items
    void checkExpiringItems()
    {
        cout << "Expiring Soon:\n";
        priority_queue<Item> tempQueue = expiryQueue;
        while (!tempQueue.empty())
        {
            Item item = tempQueue.top();
            tempQueue.pop();
            if (item.daysToExpire <= 2)
            {
                cout << "- " << item.name << " (" << item.daysToExpire << " days left)\n";
            }
        }
    }

    // Suggest recipes based on available ingredients
    void suggestRecipes()
    {
        cout << "Available Ingredients: ";
        for (const auto &pair : itemMap)
        {
            cout << pair.first << " ";
        }
        cout << "\nSuggested Recipe: Combine any available ingredients.\n";
    }

    // Display grocery history
    void displayGroceryHistory()
    {
        cout << "Grocery History:\n";
        for (const string &name : groceryHistory)
        {
            cout << "- " << name << endl;
        }
    }
};

int main()
{
    SmartFridge fridge;

    // Adding items to the fridge
    fridge.addItem("Milk", "Dairy", 3, 1);
    fridge.addItem("Eggs", "Protein", 1, 12);
    fridge.addItem("Carrots", "Vegetable", 5, 10);

    // Checking expiring items
    fridge.checkExpiringItems();

    // Suggesting recipes
    fridge.suggestRecipes();

    // Displaying grocery history
    fridge.displayGroceryHistory();

    // Removing an item
    fridge.removeItem("Milk");

    return 0;
}
