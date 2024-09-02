#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sorted_vectors(const vector<int> &vec1, const vector<int> &vec2)
{
    vector<int> fully_merged_vector; // This vector will store the final merged version of both vectors.

    int left_vector_pointer = 0;
    int right_vector_pointer = 0;

    // Main loop to merge the vectors until one is exhausted
    while (left_vector_pointer < vec1.size() && right_vector_pointer < vec2.size())
    {
        if (vec1[left_vector_pointer] < vec2[right_vector_pointer])
        {
            fully_merged_vector.push_back(vec1[left_vector_pointer]);
            left_vector_pointer++;
        }
        else
        {
            fully_merged_vector.push_back(vec2[right_vector_pointer]);
            right_vector_pointer++;
        }
    }

    // Merging the remaining elements of vec1 if any
    while (left_vector_pointer < vec1.size())
    {
        fully_merged_vector.push_back(vec1[left_vector_pointer]);
        left_vector_pointer++;
    }

    // Merging the remaining elements of vec2 if any
    while (right_vector_pointer < vec2.size())
    {
        fully_merged_vector.push_back(vec2[right_vector_pointer]);
        right_vector_pointer++;
    }

    return fully_merged_vector; // Returning the fully merged vector
}
