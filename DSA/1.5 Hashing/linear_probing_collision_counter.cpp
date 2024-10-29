#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table; // The hash table
    int size;               // Size of the hash table
    int collision_count;    // Count of collisions

public:
    // Constructor to initialize the hash table
    HashTable(int table_size) : size(table_size), collision_count(0) {
        table.resize(size, -1); // Using -1 to indicate an empty slot
    }

    // Hash function
    int hash(int key) {
        return key % size; // Basic hash function
    }

    // Insert function
    void insert(int key) {
        int index = hash(key);
        int probing_steps = 0;

        // Linear probing to find the next available slot
        while (table[index] != -1) {
            probing_steps++;
            collision_count++; // Increment collision count
            index = (index + 1) % size; // Move to the next index
            if (probing_steps >= size) {
                cout << "Hash table is full, cannot insert " << key << "\n";
                return; // Exit if we loop back to the start
            }
        }

        // Insert the key at the found index
        table[index] = key;
    }

    // Function to return total number of collisions
    int getCollisionCount() const {
        return collision_count;
    }

    // Function to display the hash table (for debugging purposes)
    void display() const {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; ++i) {
            if (table[i] == -1) {
                cout << i << ": \n";
            } else {
                cout << i << ": " << table[i] << "\n";
            }
        }
    }
};

// Function to insert an array of integers into the hash table and count collisions
int countCollisions(int arr[], int n, int table_size) {
    HashTable hash_table(table_size);

    for (int i = 0; i < n; ++i) {
        hash_table.insert(arr[i]);
    }

    return hash_table.getCollisionCount();
}

// Main function to demonstrate the functionality
int main() {
    int arr[] = {5, 15, 25, 35, 45, 55}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);
    int table_size = 10; // Size of the hash table

    int total_collisions = countCollisions(arr, n, table_size);
    
    cout << "Total collisions encountered: " << total_collisions << "\n";

    return 0;
}
