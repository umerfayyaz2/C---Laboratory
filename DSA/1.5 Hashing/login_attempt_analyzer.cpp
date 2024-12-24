#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Struct to store failed login details
struct LoginAttempt
{
    int failed_count;          // Number of failed attempts
    vector<time_t> timestamps; // Timestamps of failed attempts
};

// Class to represent the Fraudulent Login Detection System
class FraudDetectionSystem
{
private:
    unordered_map<string, LoginAttempt> user_login_attempts; // Hash map to store user login data
    int threshold;                                           // Max allowed failed attempts before flagging
    int time_window;                                         // Time window (in seconds) to check for multiple attempts

public:
    // Constructor to set threshold and time window
    FraudDetectionSystem(int max_attempts, int window) : threshold(max_attempts), time_window(window) {}

    // Record a failed login attempt for a user
    void record_failed_attempt(const string &user_id)
    {
        time_t current_time = time(nullptr); // Get current timestamp

        // If user does not exist, create an entry
        if (user_login_attempts.find(user_id) == user_login_attempts.end())
        {
            user_login_attempts[user_id] = {1, {current_time}};
        }
        else
        {
            // Update failed count and add timestamp
            user_login_attempts[user_id].failed_count++;
            user_login_attempts[user_id].timestamps.push_back(current_time);
        }

        // Check for fraudulent behavior
        if (is_fraudulent(user_id))
        {
            cout << "Fraud alert: User \"" << user_id << "\" has exceeded failed login attempts threshold.\n";
        }
    }

    // Check if a user is flagged for fraudulent behavior
    bool is_fraudulent(const string &user_id)
    {
        if (user_login_attempts.find(user_id) == user_login_attempts.end())
            return false;

        const LoginAttempt &attempts = user_login_attempts[user_id];
        if (attempts.failed_count >= threshold)
        {
            // Check if attempts occurred within the time window
            time_t current_time = time(nullptr);
            int count_in_window = 0;
            for (auto it = attempts.timestamps.rbegin(); it != attempts.timestamps.rend(); ++it)
            {
                if (current_time - *it <= time_window)
                {
                    count_in_window++;
                }
                else
                {
                    break;
                }
            }
            return count_in_window >= threshold;
        }
        return false;
    }

    // Reset failed attempts for a user (e.g., after a successful login)
    void reset_attempts(const string &user_id)
    {
        if (user_login_attempts.find(user_id) != user_login_attempts.end())
        {
            user_login_attempts.erase(user_id);
            cout << "Login attempts reset for user \"" << user_id << "\".\n";
        }
        else
        {
            cout << "No record found for user \"" << user_id << "\".\n";
        }
    }

    // Display the status of all users
    void display_all_users() const
    {
        if (user_login_attempts.empty())
        {
            cout << "No login attempts recorded.\n";
            return;
        }

        cout << "User Login Attempt Records:\n";
        for (const auto &pair : user_login_attempts)
        {
            cout << "User: " << pair.first
                 << ", Failed Attempts: " << pair.second.failed_count
                 << ", Recent Timestamp: " << pair.second.timestamps.back() << endl;
        }
    }
};

// Main function to demonstrate the Fraud Detection System
int main()
{
    // Create a fraud detection system with threshold of 3 failed attempts within 60 seconds
    FraudDetectionSystem system(3, 60);

    // Record failed login attempts for users
    system.record_failed_attempt("user123");
    system.record_failed_attempt("user123");
    system.record_failed_attempt("user456");
    system.record_failed_attempt("user123"); // This should trigger a fraud alert
    system.record_failed_attempt("user456");
    system.record_failed_attempt("user456"); // This should also trigger a fraud alert

    // Display all users and their failed attempts
    cout << "\nAll user records:\n";
    system.display_all_users();

    // Reset attempts for a user
    cout << "\nResetting attempts for user123:\n";
    system.reset_attempts("user123");

    // Display all users after reset
    cout << "\nAll user records after reset:\n";
    system.display_all_users();

    return 0;
}
