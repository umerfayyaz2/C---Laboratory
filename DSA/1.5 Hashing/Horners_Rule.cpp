#include <iostream>

unsigned int horners_hash(const string &key, int table_size)
{
    unsigned int hash_val;

    for (char ch : key)
    {
        hash_val = 37 * hash_val + ch;
    }
    return hash_val % table_size;
}