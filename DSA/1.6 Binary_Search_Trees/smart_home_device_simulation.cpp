#include <iostream>
using namespace std;

struct Device
{
    string name;
    bool isOn;
    Device *left;
    Device *right;
    Device(string n) : name(n), isOn(false), left(nullptr), right(nullptr) {}
};

void toggleDevice(Device *root)
{
    if (!root)
        return;
    root->isOn = !root->isOn;
    cout << root->name << " is now " << (root->isOn ? "On" : "Off") << endl;
    toggleDevice(root->left);
    toggleDevice(root->right);
}

int main()
{
    Device *root = new Device("Ceiling Lights");
    root->left = new Device("Rope Lights");
    root->right = new Device("Fans");

    toggleDevice(root); // Toggle all devices
    return 0;
}
