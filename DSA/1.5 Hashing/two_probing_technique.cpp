#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
private:
    vector<int> table_linear;
    vector<int> table_quadratic;
    int table_size;
    int collisions_linear;
    int collisions_quadratic;

    // Hash function
    int hashFunction(int key)
    {
        return key % table_size;
    }

public:
    HashTable(int size) : table_size(size), collisions_linear(0), collisions_quadratic(0)
    {
        table_linear.resize(size, -1);    // Initialize hash table for linear probing
        table_quadratic.resize(size, -1); // Initialize hash table for quadratic probing
    }

    // Insert using Linear Probing
    void insertLinear(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        // Linear probing to resolve collisions
        while (table_linear[(index + i) % table_size] != -1)
        {
            collisions_linear++;
            i++;
        }

        table_linear[(index + i) % table_size] = key;
    }

    // Insert using Quadratic Probing
    void insertQuadratic(int key, int c1 = 1, int c2 = 3)
    {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing to resolve collisions
        while (table_quadratic[(index + c1 * i + c2 * i * i) % table_size] != -1)
        {
            collisions_quadratic++;
            i++;
        }

        table_quadratic[(index + c1 * i + c2 * i * i) % table_size] = key;
    }

    // Function to compare and return total collisions for both probing methods
    void compareCollisions() const
    {
        cout << "Total collisions using Linear Probing: " << collisions_linear << endl;
        cout << "Total collisions using Quadratic Probing: " << collisions_quadratic << endl;
    }

    // Display tables for verification
    void displayTables() const
    {
        cout << "\nHash Table with Linear Probing:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            if (table_linear[i] != -1)
            {
                cout << "Index " << i << ": " << table_linear[i] << endl;
            }
            else
            {
                cout << "Index " << i << ": " << "empty" << endl;
            }
        }

        cout << "\nHash Table with Quadratic Probing:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            if (table_quadratic[i] != -1)
            {
                cout << "Index " << i << ": " << table_quadratic[i] << endl;
            }
            else
            {
                cout << "Index " << i << ": " << "empty" << endl;
            }
        }
    }
};

int main()
{
    int table_size;
    cout << "Enter the size of the hash table: ";
    cin >> table_size;

    HashTable hashTable(table_size);

    // Sample array of keys to insert
    vector<int> keys = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    // Insert keys using both probing methods
    for (int key : keys)
    {
        hashTable.insertLinear(key);
        hashTable.insertQuadratic(key);
    }

    // Display hash tables
    hashTable.displayTables();

    // Compare collisions
    hashTable.compareCollisions();

    return 0;
}
