#include <iostream>
#include <vector>
using namespace std;

vector<int> myVector; // Example of declaring a vector of integers

// This is how a vector's value can be accessed.
vector<int> vec = {1, 2, 3};
int x = vec[2]; // Accessing element at index 2, x is 3

// size function shows the total num of elems in a vector
vector<int> v = {1, 2, 3};
cout << v.size(); // Output: 3

// Capacity: The total number of elements a vector can hold without reallocating memory.
vector<int> v(5);     // Initializes vector with capacity for 5 elements
cout << v.capacity(); // Output: 5

// reserve function to resorve memory for future use only if you know how much memory you have to occupy
vector<int> v;
v.reserve(10); // Reserves memory for 10 elements
