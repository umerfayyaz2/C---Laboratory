#include <iostream>
#include <deque>
#include <string>
using namespace std;

class VideoBuffer
{
private:
    deque<string> buffer; // Deque to store video frames
    int maxSize;          // Maximum size of the buffer

public:
    // Constructor to set maximum buffer size
    VideoBuffer(int size) : maxSize(size) {}

    // Add a frame to the buffer (to the back)
    void addFrame(const string &frame)
    {
        if (buffer.size() == maxSize)
        {
            cout << "Buffer full. Removing oldest frame: " << buffer.front() << endl;
            buffer.pop_front(); // Remove the oldest frame
        }
        buffer.push_back(frame);
        cout << "Added frame: " << frame << endl;
    }

    // Remove a frame from the front (simulate playback)
    void playFrame()
    {
        if (buffer.empty())
        {
            cout << "No frames to play." << endl;
            return;
        }
        cout << "Playing frame: " << buffer.front() << endl;
        buffer.pop_front();
    }

    // Remove a frame from the back (discarding the most recent)
    void discardRecentFrame()
    {
        if (buffer.empty())
        {
            cout << "No frames to discard." << endl;
            return;
        }
        cout << "Discarded frame: " << buffer.back() << endl;
        buffer.pop_back();
    }

    // Display the current buffer contents
    void displayBuffer()
    {
        if (buffer.empty())
        {
            cout << "Buffer is empty." << endl;
            return;
        }
        cout << "Current buffer: ";
        for (const string &frame : buffer)
        {
            cout << frame << " ";
        }
        cout << endl;
    }
};

int main()
{
    VideoBuffer videoBuffer(5); // Create a buffer with a maximum size of 5 frames

    // Simulate adding frames
    videoBuffer.addFrame("Frame1");
    videoBuffer.addFrame("Frame2");
    videoBuffer.addFrame("Frame3");
    videoBuffer.addFrame("Frame4");
    videoBuffer.addFrame("Frame5");

    // Display the buffer
    videoBuffer.displayBuffer();

    // Add another frame (causing the buffer to remove the oldest frame)
    videoBuffer.addFrame("Frame6");

    // Play a frame
    videoBuffer.playFrame();

    // Discard the most recent frame
    videoBuffer.discardRecentFrame();

    // Display the buffer
    videoBuffer.displayBuffer();

    return 0;
}
