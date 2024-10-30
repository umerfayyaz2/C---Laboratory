#include <iostream>
#include <vector>
#include <functional> // For std::hash
using namespace std;

class CuckooHashTable
{
private:
    vector<int> table1, table2; // Two hash tables
    int table_size;
    int max_displacements; // Maximum number of displacements allowed

    // Hash functions
    int hash1(int key) const
    {
        return key % table_size;
    }

    int hash2(int key) const
    {
        return (key / table_size) % table_size;
    }

public:
    CuckooHashTable(int size, int max_disp) : table_size(size), max_displacements(max_disp)
    {
        table1.resize(size, -1); // Initialize table1 with -1 (empty)
        table2.resize(size, -1); // Initialize table2 with -1 (empty)
    }

    // Insert a key with displacement tracking
    int insertAndCount(int key)
    {
        int count_displacements = 0; // Track number of displacements
        int curr_key = key;
        int location, temp;

        for (int i = 0; i < max_displacements; i++)
        {
            // Try to place in table1
            location = hash1(curr_key);
            if (table1[location] == -1)
            {
                table1[location] = curr_key;
                return count_displacements; // Successful insertion
            }

            // Displace existing key in table1
            count_displacements++;
            temp = table1[location];
            table1[location] = curr_key;
            curr_key = temp; // Current key to place is the displaced one

            // Try to place in table2
            location = hash2(curr_key);
            if (table2[location] == -1)
            {
                table2[location] = curr_key;
                return count_displacements; // Successful insertion
            }

            // Displace existing key in table2
            count_displacements++;
            temp = table2[location];
            table2[location] = curr_key;
            curr_key = temp; // Current key to place is the displaced one
        }

        // Insertion failed due to displacement limit
        return -1;
    }

    // Display the contents of both tables for verification
    void displayTables() const
    {
        cout << "Table 1: ";
        for (int i = 0; i < table_size; i++)
        {
            if (table1[i] != -1)
            {
                cout << table1[i] << " ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout << "\nTable 2: ";
        for (int i = 0; i < table_size; i++)
        {
            if (table2[i] != -1)
            {
                cout << table2[i] << " ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int table_size = 11;
    int max_displacements = 5;

    CuckooHashTable hashTable(table_size, max_displacements);

    // Sample keys to insert
    vector<int> keys = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};

    // Insert keys and track displacements
    for (int key : keys)
    {
        int result = hashTable.insertAndCount(key);
        if (result != -1)
        {
            cout << "Inserted key " << key << " with " << result << " displacements.\n";
        }
        else
        {
            cout << "Failed to insert key " << key << " due to excessive displacements. Consider rehashing.\n";
        }
    }

    // Display hash tables
    hashTable.displayTables();

    return 0;
}
