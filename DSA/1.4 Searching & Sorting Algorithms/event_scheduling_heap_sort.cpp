#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Structure to represent an event or meeting
struct event
{
    int start_time;
    int end_time;

    event(int start, int end) : start_time(start), end_time(end) {}
};

// Function to heapify a subtree rooted at index `i`
void heapify(vector<event> &events, int n, int i)
{
    int largest = i;             // Initialize largest as root
    int left_child = 2 * i + 1;  // Left child index
    int right_child = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left_child < n && events[left_child].start_time > events[largest].start_time)
    {
        largest = left_child;
    }

    // If right child is larger than the largest so far
    if (right_child < n && events[right_child].start_time > events[largest].start_time)
    {
        largest = right_child;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(events[i], events[largest]);
        heapify(events, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to perform heap sort on events based on start times
void heap_sort(vector<event> &events)
{
    int n = events.size();

    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(events, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(events[0], events[i]); // Move current root to the end
        heapify(events, i, 0);      // Heapify the reduced heap
    }
}

// Function to allocate meeting rooms and print the schedule
void allocate_resources(vector<event> &events)
{
    heap_sort(events); // Sort events by start times using heap sort

    // Min-heap to track end times of ongoing meetings
    priority_queue<int, vector<int>, greater<int>> meeting_end_times;

    int room_count = 0; // Tracks total number of rooms used

    cout << "Event Schedule with Room Allocation:\n";
    for (const auto &ev : events)
    {
        // If the earliest meeting has ended, free the room
        if (!meeting_end_times.empty() && meeting_end_times.top() <= ev.start_time)
        {
            meeting_end_times.pop();
        }
        else
        {
            room_count++; // Allocate a new room
        }

        // Push the end time of the current meeting
        meeting_end_times.push(ev.end_time);

        cout << "Event (" << ev.start_time << ", " << ev.end_time
             << ") allocated to a room.\n";
    }

    cout << "Total rooms required: " << room_count << endl;
}

// Main function to demonstrate the scheduling
int main()
{
    vector<event> events = {
        {1, 4}, {2, 5}, {3, 6}, {7, 9}, {10, 12}, {5, 8}};

    allocate_resources(events);

    return 0;
}
