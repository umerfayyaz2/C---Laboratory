#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Class to represent a Conference Room Booking System
class ConferenceRoomBooking
{
private:
    unordered_map<string, bool> room_availability; // Hash map for room ID and its availability status

public:
    // Add a conference room to the system
    void add_room(const string &room_id)
    {
        if (room_availability.find(room_id) == room_availability.end())
        {
            room_availability[room_id] = true; // Mark the room as available
            cout << "Room " << room_id << " has been added and is available.\n";
        }
        else
        {
            cout << "Room " << room_id << " already exists.\n";
        }
    }

    // Book a room if available
    void book_room(const string &room_id)
    {
        auto it = room_availability.find(room_id);
        if (it != room_availability.end())
        {
            if (it->second)
            {                       // Check if the room is available
                it->second = false; // Mark the room as booked
                cout << "Room " << room_id << " has been successfully booked.\n";
            }
            else
            {
                cout << "Room " << room_id << " is already booked.\n";
            }
        }
        else
        {
            cout << "Room " << room_id << " does not exist.\n";
        }
    }

    // Release a room (mark it as available)
    void release_room(const string &room_id)
    {
        auto it = room_availability.find(room_id);
        if (it != room_availability.end())
        {
            if (!it->second)
            {                      // Check if the room is booked
                it->second = true; // Mark the room as available
                cout << "Room " << room_id << " has been released and is now available.\n";
            }
            else
            {
                cout << "Room " << room_id << " is already available.\n";
            }
        }
        else
        {
            cout << "Room " << room_id << " does not exist.\n";
        }
    }

    // Check the availability of a room
    void check_availability(const string &room_id) const
    {
        auto it = room_availability.find(room_id);
        if (it != room_availability.end())
        {
            if (it->second)
            {
                cout << "Room " << room_id << " is available.\n";
            }
            else
            {
                cout << "Room " << room_id << " is booked.\n";
            }
        }
        else
        {
            cout << "Room " << room_id << " does not exist.\n";
        }
    }

    // Display the status of all rooms
    void display_all_rooms() const
    {
        if (room_availability.empty())
        {
            cout << "No rooms are currently available in the system.\n";
            return;
        }

        cout << "Conference Room Status:\n";
        for (const auto &entry : room_availability)
        {
            cout << "Room " << entry.first << ": "
                 << (entry.second ? "Available" : "Booked") << endl;
        }
    }
};

// Main function to test the Conference Room Booking system
int main()
{
    ConferenceRoomBooking system;

    // Add conference rooms to the system
    system.add_room("Room101");
    system.add_room("Room102");
    system.add_room("Room103");

    // Check the availability of a specific room
    cout << "\nChecking room availability:\n";
    system.check_availability("Room101");
    system.check_availability("Room200");

    // Book a room
    cout << "\nBooking a room:\n";
    system.book_room("Room101");
    system.book_room("Room101");

    // Release a room
    cout << "\nReleasing a room:\n";
    system.release_room("Room101");
    system.release_room("Room101");

    // Display the status of all rooms
    cout << "\nDisplaying all room statuses:\n";
    system.display_all_rooms();

    return 0;
}
