#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct RobotNode
{
    int robotID; // Unique ID for each robot
    RobotNode *left;
    RobotNode *right;

    RobotNode(int id) : robotID(id), left(nullptr), right(nullptr) {}
};

class IoTWarehouse
{
private:
    RobotNode *root;                        // Root of the binary tree
    unordered_map<int, string> taskDetails; // Maps robotID to task details

public:
    IoTWarehouse() : root(nullptr) {}

    // Insert robot into the binary tree by zone (simplified for demo)
    RobotNode *addRobot(RobotNode *node, int robotID)
    {
        if (!node)
            return new RobotNode(robotID);
        if (robotID < node->robotID)
            node->left = addRobot(node->left, robotID);
        else
            node->right = addRobot(node->right, robotID);
        return node;
    }

    void addRobot(int robotID, const string &task)
    {
        root = addRobot(root, robotID);
        taskDetails[robotID] = task; // Add task details in hash table
    }

    // Search for a robot in the binary tree by zone
    bool findRobot(RobotNode *node, int robotID)
    {
        if (!node)
            return false;
        if (node->robotID == robotID)
            return true;
        return (robotID < node->robotID) ? findRobot(node->left, robotID) : findRobot(node->right, robotID);
    }

    bool isRobotInZone(int robotID)
    {
        return findRobot(root, robotID);
    }

    // Query task details for a specific robot
    string getTaskDetails(int robotID)
    {
        return taskDetails.count(robotID) ? taskDetails[robotID] : "No task found.";
    }
};

int main()
{
    IoTWarehouse warehouse;

    // Add robots and their tasks
    warehouse.addRobot(10, "Pick items from Zone A");
    warehouse.addRobot(20, "Sort items in Zone B");
    warehouse.addRobot(5, "Transport items to Zone C");

    // Check if a robot is in a specific zone
    cout << "Is robot 10 in the zone? " << (warehouse.isRobotInZone(10) ? "Yes" : "No") << "\n";

    // Query task details
    cout << "Task for robot 10: " << warehouse.getTaskDetails(10) << "\n";
    cout << "Task for robot 15: " << warehouse.getTaskDetails(15) << "\n";

    return 0;
}
