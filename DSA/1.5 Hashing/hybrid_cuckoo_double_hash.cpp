#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class HybridHashTable
{
private:
    vector<int> table1, table2, backupTable; // Two tables for cuckoo and one for double hashing
    int table_size;
    int max_displacements;

    // Cuckoo hash functions
    int hash1(int key) const
    {
        return key % table_size;
    }

    int hash2(int key) const
    {
        return (key / table_size) % table_size;
    }

    // Double hashing hash functions for backup table
    int doubleHash1(int key) const
    {
        return key % table_size;
    }

    int doubleHash2(int key) const
    {
        return 1 + (key % (table_size - 1)); // Avoids zero for secondary step size
    }

public:
    HybridHashTable(int size, int max_disp) : table_size(size), max_displacements(max_disp)
    {
        table1.resize(size, -1);      // Initialize table1 with -1
        table2.resize(size, -1);      // Initialize table2 with -1
        backupTable.resize(size, -1); // Backup table for double hashing
    }

    // Insert a key using hybrid cuckoo and double hashing
    bool insert(int key)
    {
        int curr_key = key;
        int location, temp;

        // Try cuckoo hashing first
        for (int i = 0; i < max_displacements; i++)
        {
            // Try to place in table1
            location = hash1(curr_key);
            if (table1[location] == -1)
            {
                table1[location] = curr_key;
                return true;
            }

            // Displace existing key in table1
            temp = table1[location];
            table1[location] = curr_key;
            curr_key = temp;

            // Try to place in table2
            location = hash2(curr_key);
            if (table2[location] == -1)
            {
                table2[location] = curr_key;
                return true;
            }

            // Displace existing key in table2
            temp = table2[location];
            table2[location] = curr_key;
        }

        // If maximum displacements reached, use double hashing
        cout << "Switching to double hashing for key " << key << endl;
        int double_hash_index = doubleHash1(key);
        int step_size = doubleHash2(key);

        // Linear probing with step size from double hashing
        for (int i = 0; i < table_size; i++)
        {
            int probe_index = (double_hash_index + i * step_size) % table_size;
            if (backupTable[probe_index] == -1)
            {
                backupTable[probe_index] = key;
                return true;
            }
        }

        // Table is full or rehashing needed
        cout << "Insertion failed for key " << key << "; rehashing may be required." << endl;
        return false;
    }

    // Search for a key in both cuckoo tables and the backup table
    bool search(int key) const
    {
        // Search in table1
        int location = hash1(key);
        if (table1[location] == key)
            return true;

        // Search in table2
        location = hash2(key);
        if (table2[location] == key)
            return true;

        // Search in backup table using double hashing
        int double_hash_index = doubleHash1(key);
        int step_size = doubleHash2(key);

        for (int i = 0; i < table_size; i++)
        {
            int probe_index = (double_hash_index + i * step_size) % table_size;
            if (backupTable[probe_index] == key)
                return true;
            if (backupTable[probe_index] == -1)
                break; // Stop search if empty slot encountered
        }

        return false;
    }

    // Display all hash tables for debugging
    void displayTables() const
    {
        cout << "Table 1 (Cuckoo): ";
        for (int val : table1)
        {
            if (val != -1)
                cout << val << " ";
            else
                cout << "- ";
        }
        cout << "\nTable 2 (Cuckoo): ";
        for (int val : table2)
        {
            if (val != -1)
                cout << val << " ";
            else
                cout << "- ";
        }
        cout << "\nBackup Table (Double Hashing): ";
        for (int val : backupTable)
        {
            if (val != -1)
                cout << val << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
};

int main()
{
    int table_size = 11;
    int max_displacements = 5;

    HybridHashTable hashTable(table_size, max_displacements);

    // Sample keys to insert
    vector<int> keys = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};

    // Insert keys
    for (int key : keys)
    {
        if (hashTable.insert(key))
        {
            cout << "Inserted key " << key << endl;
        }
        else
        {
            cout << "Failed to insert key " << key << endl;
        }
    }

    // Display tables
    hashTable.displayTables();

    // Search for some keys
    cout << "Searching for keys:\n";
    for (int key : keys)
    {
        if (hashTable.search(key))
        {
            cout << "Key " << key << " found." << endl;
        }
        else
        {
            cout << "Key " << key << " not found." << endl;
        }
    }

    return 0;
}
