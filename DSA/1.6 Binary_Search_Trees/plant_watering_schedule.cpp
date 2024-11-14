#include <iostream>
using namespace std;

struct Plant
{
    string name;
    bool watered;
    Plant *left;
    Plant *right;
    Plant(string n) : name(n), watered(false), left(nullptr), right(nullptr) {}
};

void waterPlants(Plant *root)
{
    if (!root)
        return;
    root->watered = true;
    cout << root->name << " watered!" << endl;
    waterPlants(root->left);
    waterPlants(root->right);
}

int main()
{
    Plant *garden = new Plant("Rose");
    garden->left = new Plant("Lily");
    garden->right = new Plant("Tulip");

    waterPlants(garden);
    return 0;
}
