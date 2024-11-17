#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Class for managing smartphone notifications
class NotificationQueue
{
private:
    queue<string> notifications; // Queue to store notifications

public:
    // Add a notification to the queue
    void addNotification(const string &notification)
    {
        notifications.push(notification);
        cout << "Notification added: \"" << notification << "\"" << endl;
    }

    // Process and display the oldest notification
    void processNotification()
    {
        if (notifications.empty())
        {
            cout << "No notifications to process!" << endl;
            return;
        }
        cout << "Processing notification: \"" << notifications.front() << "\"" << endl;
        notifications.pop(); // Remove the oldest notification from the queue
    }

    // Display all pending notifications
    void displayNotifications()
    {
        if (notifications.empty())
        {
            cout << "No pending notifications!" << endl;
            return;
        }

        cout << "Pending notifications:" << endl;
        queue<string> tempQueue = notifications; // Copy to avoid modifying the original queue
        while (!tempQueue.empty())
        {
            cout << "- " << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
};

int main()
{
    NotificationQueue notificationQueue;

    // Add notifications
    notificationQueue.addNotification("New message from John");
    notificationQueue.addNotification("Update available for your app");
    notificationQueue.addNotification("Your order has been shipped");

    // Display pending notifications
    notificationQueue.displayNotifications();

    // Process notifications
    notificationQueue.processNotification();
    notificationQueue.processNotification();

    // Display remaining notifications
    notificationQueue.displayNotifications();

    // Process another notification
    notificationQueue.processNotification();

    // Attempt to process a notification when the queue is empty
    notificationQueue.processNotification();

    return 0;
}
