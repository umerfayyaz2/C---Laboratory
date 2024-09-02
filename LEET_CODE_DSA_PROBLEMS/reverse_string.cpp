#include <iostream>
#include <vector>
using namespace std;

void reverse_string(vector<char> &string_to_reverse)
{
    int starting_index = 0;
    int ending_index = string_to_reverse.size() - 1;

    while (starting_index < ending_index)
    {
        swap(string_to_reverse[starting_index], string_to_reverse[ending_index]);
        starting_index++;
        ending_index--;
    }
}
