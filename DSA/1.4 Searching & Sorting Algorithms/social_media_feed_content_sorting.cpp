#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Content class to represent each post or content in the social media feed
class Content
{
public:
    string post_text; // Text of the post
    int timestamp;    // Timestamp when the post was created

    // Constructor to initialize the content post
    Content(string post_text, int timestamp) : post_text(post_text), timestamp(timestamp) {}
};

// SocialMediaFeed class to represent the social media feed
class SocialMediaFeed
{
private:
    vector<Content> feed; // Vector to store the content of the feed

public:
    // Function to add new post to the feed
    void add_post(const string &post_text, int timestamp)
    {
        Content new_content(post_text, timestamp);
        feed.push_back(new_content);
        insertion_sort(feed); // Sort the feed every time a new post is added
    }

    // Function to display the sorted posts (latest post first)
    void display_feed()
    {
        for (auto &content : feed)
        {
            cout << "Post: " << content.post_text << ", Timestamp: " << content.timestamp << endl;
        }
    }

private:
    // Function to sort the feed using insertion sort based on the timestamp
    void insertion_sort(vector<Content> &arr)
    {
        for (int curr = 1; curr < arr.size(); curr++)
        {                            // curr index starts from the second elem
            Content key = arr[curr]; // the key is our curr indexed elem
            int prev = curr - 1;     // prev is the index before curr

            while (prev >= 0 && arr[prev].timestamp > key.timestamp)
            {
                arr[prev + 1] = arr[prev];
                prev = prev - 1; // base case
            }

            // Insert the key at the correct position
            arr[prev + 1] = key;
        }
    }
};

int main()
{
    SocialMediaFeed feed;

    // Adding some posts with their timestamps
    feed.add_post("Just finished reading a book!", 1609459200);     // Timestamp for Jan 1, 2021
    feed.add_post("Had a great workout today!", 1609545600);        // Timestamp for Jan 2, 2021
    feed.add_post("Loving the new series on Netflix!", 1609632000); // Timestamp for Jan 3, 2021

    // Display the sorted feed
    cout << "Social Media Feed (Sorted by Timestamp):" << endl;
    feed.display_feed();

    return 0;
}
