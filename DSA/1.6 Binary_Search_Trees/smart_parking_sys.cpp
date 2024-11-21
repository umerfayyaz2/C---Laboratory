#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>
using namespace std;

struct SlotNode
{
    int slotNumber;  // Unique parking slot number
    bool isOccupied; // Slot status
    SlotNode *left;
    SlotNode *right;

    SlotNode(int num) : slotNumber(num), isOccupied(false), left(nullptr), right(nullptr) {}
};

class SmartParkingSystem
{
private:
    SlotNode *root;                                       // Root of the binary tree
    unordered_map<string, pair<int, time_t>> vehicleData; // License -> (slotNumber, entryTime)

public:
    SmartParkingSystem() : root(nullptr) {}

    // Add a parking slot to the binary tree
    SlotNode *addSlot(SlotNode *node, int slotNumber)
    {
        if (!node)
            return new SlotNode(slotNumber);
        if (slotNumber < node->slotNumber)
            node->left = addSlot(node->left, slotNumber);
        else
            node->right = addSlot(node->right, slotNumber);
        return node;
    }

    void addSlot(int slotNumber)
    {
        root = addSlot(root, slotNumber);
    }

    // Find the first available slot
    SlotNode *findAvailableSlot(SlotNode *node)
    {
        if (!node || node->isOccupied)
            return nullptr;
        SlotNode *leftSlot = findAvailableSlot(node->left);
        if (leftSlot)
            return leftSlot;
        return node->isOccupied ? findAvailableSlot(node->right) : node;
    }

    // Park a vehicle in the first available slot
    void parkVehicle(const string &licensePlate)
    {
        SlotNode *availableSlot = findAvailableSlot(root);
        if (!availableSlot)
        {
            cout << "No available slots.\n";
            return;
        }
        availableSlot->isOccupied = true;
        time_t entryTime = time(nullptr);
        vehicleData[licensePlate] = {availableSlot->slotNumber, entryTime};
        cout << "Vehicle with license " << licensePlate << " parked in slot " << availableSlot->slotNumber << ".\n";
    }

    // Remove a vehicle from a slot
    void removeVehicle(const string &licensePlate)
    {
        if (!vehicleData.count(licensePlate))
        {
            cout << "Vehicle with license " << licensePlate << " not found.\n";
            return;
        }
        int slotNumber = vehicleData[licensePlate].first;
        time_t entryTime = vehicleData[licensePlate].second;
        vehicleData.erase(licensePlate);
        markSlotAvailable(root, slotNumber);
        cout << "Vehicle with license " << licensePlate << " removed from slot " << slotNumber
             << ". Parked for " << (time(nullptr) - entryTime) << " seconds.\n";
    }

    // Mark a slot as available
    void markSlotAvailable(SlotNode *node, int slotNumber)
    {
        if (!node)
            return;
        if (node->slotNumber == slotNumber)
            node->isOccupied = false;
        else if (slotNumber < node->slotNumber)
            markSlotAvailable(node->left, slotNumber);
        else
            markSlotAvailable(node->right, slotNumber);
    }

    // Find which slot a specific car is parked in
    void queryVehicleSlot(const string &licensePlate)
    {
        if (!vehicleData.count(licensePlate))
        {
            cout << "Vehicle with license " << licensePlate << " not found.\n";
            return;
        }
        int slotNumber = vehicleData[licensePlate].first;
        cout << "Vehicle with license " << licensePlate << " is parked in slot " << slotNumber << ".\n";
    }

    // Check the status of a slot
    void checkSlotStatus(int slotNumber)
    {
        SlotNode *slot = findSlot(root, slotNumber);
        if (!slot)
        {
            cout << "Slot " << slotNumber << " not found.\n";
            return;
        }
        cout << "Slot " << slotNumber << (slot->isOccupied ? " is occupied.\n" : " is available.\n");
    }

    // Find a specific slot in the tree
    SlotNode *findSlot(SlotNode *node, int slotNumber)
    {
        if (!node)
            return nullptr;
        if (node->slotNumber == slotNumber)
            return node;
        if (slotNumber < node->slotNumber)
            return findSlot(node->left, slotNumber);
        return findSlot(node->right, slotNumber);
    }
};

int main()
{
    SmartParkingSystem parking;

    // Add parking slots
    parking.addSlot(1);
    parking.addSlot(2);
    parking.addSlot(3);

    // Park vehicles
    parking.parkVehicle("ABC123");
    parking.parkVehicle("XYZ789");

    // Query vehicle slot
    parking.queryVehicleSlot("ABC123");

    // Check slot status
    parking.checkSlotStatus(1);
    parking.checkSlotStatus(2);

    // Remove a vehicle
    parking.removeVehicle("ABC123");
    parking.checkSlotStatus(1);

    return 0;
}
