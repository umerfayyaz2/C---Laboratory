#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class ScreenSharingSystem
{
private:
    unordered_map<int, bool> participant_map; // Maps participant ID to screen-sharing status
    stack<int> screen_sharers;                // Stack to maintain order of active screen sharers

public:
    // Function to request screen sharing for a participant
    void request_screen_share(int participant_id)
    {
        // Check if the participant is already sharing their screen
        if (participant_map[participant_id] == true)
        {
            cout << "Participant " << participant_id << " is already sharing their screen.\n";
        }
        else
        {
            // Add the participant to the stack and mark as sharing
            participant_map[participant_id] = true;
            screen_sharers.push(participant_id);
            cout << "Participant " << participant_id << " started sharing their screen.\n";
        }
    }

    // Function to stop screen sharing for the last participant in the stack
    void stop_screen_share()
    {
        // Ensure there's someone sharing their screen
        if (screen_sharers.empty())
        {
            cout << "No participant is currently sharing their screen.\n";
        }
        else
        {
            int participant_id = screen_sharers.top(); // Get the last participant in stack
            screen_sharers.pop();                      // Remove from the stack
            participant_map[participant_id] = false;   // Mark as not sharing
            cout << "Participant " << participant_id << " stopped sharing their screen.\n";
        }
    }

    // Function to show the current screen sharer
    void show_current_screen_sharer()
    {
        if (screen_sharers.empty())
        {
            cout << "No one is currently sharing their screen.\n";
        }
        else
        {
            int participant_id = screen_sharers.top();
            cout << "Currently, Participant " << participant_id << " is sharing their screen.\n";
        }
    }

    // Function to show all participants who are sharing their screens
    void show_all_screen_sharers()
    {
        if (screen_sharers.empty())
        {
            cout << "No participants are sharing their screens.\n";
        }
        else
        {
            cout << "Currently sharing screens: ";
            stack<int> temp_stack = screen_sharers; // Temporary stack to display participants
            while (!temp_stack.empty())
            {
                cout << temp_stack.top() << " ";
                temp_stack.pop();
            }
            cout << "\n";
        }
    }
};

int main()
{
    ScreenSharingSystem screen_sharing_system;

    // Request screen sharing
    screen_sharing_system.request_screen_share(101);
    screen_sharing_system.request_screen_share(102);
    screen_sharing_system.request_screen_share(103);

    // Show current screen sharer
    screen_sharing_system.show_current_screen_sharer();

    // Stop screen sharing
    screen_sharing_system.stop_screen_share();
    screen_sharing_system.show_current_screen_sharer();

    // Show all screen sharers
    screen_sharing_system.show_all_screen_sharers();

    return 0;
}
