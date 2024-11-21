#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct RegionNode
{
    int regionId; // Unique ID for each region
    RegionNode *left;
    RegionNode *right;
    vector<int> vehicles; // List of vehicle IDs in this region

    RegionNode(int id) : regionId(id), left(nullptr), right(nullptr) {}
};

class FleetManagement
{
private:
    RegionNode *root;                                        // Root of the binary tree
    unordered_map<int, tuple<int, int, string>> vehicleData; // Vehicle ID -> (speed, fuel, location)

public:
    FleetManagement() : root(nullptr) {}

    // Add a region to the binary tree
    RegionNode *addRegion(RegionNode *node, int regionId)
    {
        if (!node)
            return new RegionNode(regionId);
        if (regionId < node->regionId)
            node->left = addRegion(node->left, regionId);
        else
            node->right = addRegion(node->right, regionId);
        return node;
    }

    void addRegion(int regionId)
    {
        root = addRegion(root, regionId);
    }

    // Add a vehicle to a region and store metadata
    void addVehicle(int regionId, int vehicleId, int speed, int fuel, const string &location)
    {
        RegionNode *region = findRegion(root, regionId);
        if (!region)
        {
            cout << "Region " << regionId << " does not exist. Adding it.\n";
            addRegion(regionId);
            region = findRegion(root, regionId);
        }
        region->vehicles.push_back(vehicleId);
        vehicleData[vehicleId] = {speed, fuel, location};
    }

    // Find a region in the binary tree
    RegionNode *findRegion(RegionNode *node, int regionId)
    {
        if (!node)
            return nullptr;
        if (node->regionId == regionId)
            return node;
        if (regionId < node->regionId)
            return findRegion(node->left, regionId);
        return findRegion(node->right, regionId);
    }

    // Query vehicles in a region
    void queryVehiclesInRegion(int regionId)
    {
        RegionNode *region = findRegion(root, regionId);
        if (!region)
        {
            cout << "Region " << regionId << " not found.\n";
            return;
        }
        cout << "Vehicles in Region " << regionId << ": ";
        for (int vehicleId : region->vehicles)
        {
            cout << vehicleId << " ";
        }
        cout << "\n";
    }

    // Get metadata for a specific vehicle
    void queryVehicleData(int vehicleId)
    {
        if (vehicleData.count(vehicleId))
        {
            auto [speed, fuel, location] = vehicleData[vehicleId];
            cout << "Vehicle " << vehicleId << " -> Speed: " << speed
                 << ", Fuel: " << fuel << ", Location: " << location << "\n";
        }
        else
        {
            cout << "Vehicle " << vehicleId << " not found.\n";
        }
    }
};

int main()
{
    FleetManagement fleet;

    // Add regions
    fleet.addRegion(1);
    fleet.addRegion(2);

    // Add vehicles
    fleet.addVehicle(1, 101, 60, 50, "Zone A");
    fleet.addVehicle(1, 102, 70, 40, "Zone B");
    fleet.addVehicle(2, 201, 80, 70, "Zone C");

    // Query vehicles in a region
    fleet.queryVehiclesInRegion(1); // Outputs: Vehicles in Region 1: 101 102
    fleet.queryVehiclesInRegion(3); // Outputs: Region 3 not found.

    // Query specific vehicle data
    fleet.queryVehicleData(101); // Outputs: Vehicle 101 -> Speed: 60, Fuel: 50, Location: Zone A
    fleet.queryVehicleData(202); // Outputs: Vehicle 202 not found.

    return 0;
}
