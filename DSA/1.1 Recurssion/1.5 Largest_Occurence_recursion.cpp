#include <iostream>
using namespace std;

int largest(const int list[], int lower_index, int upper_index);

int main()
{
    int list[] = {5, 2, 3, 9, 7, 12}; // lenght = 6 (0-5)

    cout << "The Largest occurence in the Array List is: " << largest(list, 0, 5);
}

int largest(const int list[], int lower_index, int upper_index)
{
    int largest_occurence; // declared a varaible to store the largest occurence in the array.

    if (lower_index == upper_index) // setting up the base case to avoid inifinite recursion
        return list[lower_index];
    else
        largest_occurence = largest(list, lower_index + 1, upper_index); // the program will start the recursion until the base case is true and then it moves to the next line.

    if (lower_index >= largest_occurence) // here largest occurence now holds a value which is being checked to the changed lower_index
        return list[lower_index];
    else
        return largest_occurence; // finally it'll return the largest occurence in the array.
}