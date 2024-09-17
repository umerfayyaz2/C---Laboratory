#include <iostream>
#include <vector>
using namespace std;

vector<int> myVector; // Example of declaring a vector of integers

// This is how a vector's value can be accessed.
vector<int> vec = {1, 2, 3};
int x = vec[2]; // Accessing element at index 2, x is 3

vector<int> v = {1, 2, 3};
cout << v.size(); // Output: 3

vector<int> v(5);     // Initializes vector with capacity for 5 elements
cout << v.capacity(); // Output: 5
