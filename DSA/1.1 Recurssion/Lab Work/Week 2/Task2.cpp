#include <iostream>
using namespace std;

int main()
{
    int size = 11;
    int arr[size] = {1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13};
    int target = 13;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] + arr[i + 1] == target)
        {
            cout << i << " " << i + 1 << endl;
        }
    }

    return 0;
}
