#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Participant structure to track noise level and last activity time
struct Participant
{
    int noise_level;
    chrono::steady_clock::time_point last_active;
};

class AutoMuteSystem
{
private:
    unordered_map<int, Participant> participant_map; // Maps participant ID to their data
    queue<int> activity_queue;                       // Queue to track participants in the sliding window
    int noise_threshold;                             // Maximum allowed noise level
    int inactivity_time;                             // Maximum inactivity time (in seconds)

public:
    // Constructor to initialize thresholds
    AutoMuteSystem(int max_noise, int max_inactivity)
    {
        noise_threshold = max_noise;
        inactivity_time = max_inactivity;
    }

    // Function to add or update participant activity
    void update_activity(int participant_id, int noise)
    {
        auto current_time = chrono::steady_clock::now();

        // Update participant data
        if (participant_map.find(participant_id) == participant_map.end())
        {
            // New participant
            participant_map[participant_id] = {noise, current_time};
            cout << "Participant " << participant_id << " joined with noise level " << noise << ".\n";
        }
        else
        {
            // Update existing participant
            participant_map[participant_id].noise_level = noise;
            participant_map[participant_id].last_active = current_time;
            cout << "Participant " << participant_id << " updated with noise level " << noise << ".\n";
        }

        // Add participant to the activity queue
        activity_queue.push(participant_id);
    }

    // Function to check and mute participants
    void check_and_mute()
    {
        auto current_time = chrono::steady_clock::now();

        while (!activity_queue.empty())
        {
            int participant_id = activity_queue.front();
            auto &participant = participant_map[participant_id];

            // Check noise level
            if (participant.noise_level > noise_threshold)
            {
                cout << "Participant " << participant_id << " muted due to high noise level.\n";
                participant_map.erase(participant_id); // Remove from active participants
                activity_queue.pop();                  // Remove from queue
                continue;
            }

            // Check inactivity time
            auto time_since_last_active = chrono::duration_cast<chrono::seconds>(current_time - participant.last_active).count();
            if (time_since_last_active > inactivity_time)
            {
                cout << "Participant " << participant_id << " muted due to inactivity.\n";
                participant_map.erase(participant_id); // Remove from active participants
                activity_queue.pop();                  // Remove from queue
                continue;
            }

            // If neither condition is met, stop checking (sliding window)
            break;
        }
    }

    // Display active participants
    void show_active_participants()
    {
        cout << "Active Participants:\n";
        for (const auto &[participant_id, participant_data] : participant_map)
        {
            cout << "Participant ID: " << participant_id << ", Noise Level: " << participant_data.noise_level << "\n";
        }
    }
};

int main()
{
    // Initialize auto-mute system with thresholds
    AutoMuteSystem auto_mute_system(10, 5); // Noise threshold = 10, inactivity threshold = 5 seconds

    // Simulate participant activity
    auto_mute_system.update_activity(101, 5);
    auto_mute_system.update_activity(102, 12); // High noise level
    auto_mute_system.update_activity(103, 3);

    // Wait for 6 seconds to simulate inactivity
    this_thread::sleep_for(chrono::seconds(6));

    auto_mute_system.check_and_mute();           // Check and mute participants
    auto_mute_system.show_active_participants(); // Show remaining active participants

    return 0;
}
