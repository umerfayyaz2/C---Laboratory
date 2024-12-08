#include <iostream>
#include <vector>
#include <algorithm> // For binary search
#include <ctime>     // For generating current time
using namespace std;

class RateLimiter
{
private:
    int max_requests;             // Maximum requests allowed
    vector<long long> timestamps; // List to store timestamps of requests

public:
    // Constructor to initialize rate limiter with max requests per second
    RateLimiter(int N) : max_requests(N) {}

    // Function to check if the request can be made
    bool canMakeRequest()
    {
        long long current_time = time(0); // Get current timestamp (in seconds)

        // Remove timestamps that are outside the allowed time window (N seconds ago)
        while (!timestamps.empty() && timestamps.front() <= current_time - 1)
        {
            timestamps.erase(timestamps.begin()); // Remove the earliest request
        }

        // Check if the number of requests within the window exceeds the limit
        if (timestamps.size() < max_requests)
        {
            timestamps.push_back(current_time); // Add new request timestamp
            return true;                        // Request allowed
        }

        return false; // Request denied (rate limit exceeded)
    }
};

int main()
{
    RateLimiter rate_limiter(3); // Max 3 requests per second

    // Simulate requests and check if they are allowed
    for (int i = 0; i < 5; ++i)
    {
        if (rate_limiter.canMakeRequest())
        {
            cout << "Request " << i + 1 << " allowed.\n";
        }
        else
        {
            cout << "Request " << i + 1 << " denied: Rate limit exceeded.\n";
        }
    }

    return 0;
}
