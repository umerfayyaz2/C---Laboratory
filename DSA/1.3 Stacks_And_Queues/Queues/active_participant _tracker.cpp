#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Active_Participant_Tracker
{
private:
    unordered_map<int, bool> participant_status; // Store participant ID and their active status
    queue<pair<int, string>> event_queue;        // Queue to track join/leave events in real-time

public:
    // Function to add a participant
    void join(int participant_id)
    {
        // Mark participant as active
        participant_status[participant_id] = true;
        event_queue.push({participant_id, "joined"});
        cout << "Participant " << participant_id << " has joined.\n";
    }

    // Function to remove a participant
    void leave(int participant_id)
    {
        if (participant_status.find(participant_id) != participant_status.end() && participant_status[participant_id])
        {
            // Mark participant as inactive
            participant_status[participant_id] = false;
            event_queue.push({participant_id, "left"});
            cout << "Participant " << participant_id << " has left.\n";
        }
        else
        {
            cout << "Participant " << participant_id << " was not found or is already inactive.\n";
        }
    }

    // Function to get the current number of active participants
    int get_active_participants_count()
    {
        int active_count = 0;
        // Count how many participants are active
        for (auto &entry : participant_status)
        {
            if (entry.second)
            {
                active_count++;
            }
        }
        return active_count;
    }

    // Function to display join/leave events
    void show_events()
    {
        cout << "Event History:\n";
        while (!event_queue.empty())
        {
            auto event = event_queue.front();
            event_queue.pop();
            cout << "Participant " << event.first << " " << event.second << ".\n";
        }
    }
};

int main()
{
    Active_Participant_Tracker tracker;

    // Example usage
    tracker.join(101);
    tracker.join(102);
    tracker.join(103);

    cout << "Current active participants: " << tracker.get_active_participants_count() << "\n";

    tracker.leave(102);
    tracker.leave(104); // Non-existent participant

    cout << "Current active participants: " << tracker.get_active_participants_count() << "\n";

    // Display the events of joining and leaving
    tracker.show_events();

    return 0;
}
