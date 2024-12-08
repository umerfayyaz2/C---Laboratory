#include <iostream>
#include <vector>

using namespace std;

// Define a struct to represent a player and their score
struct Player
{
    string name; // Player's name
    int score;   // Player's score
};

// Function to display the leaderboard
void displayLeaderboard(const vector<Player> &leaderboard)
{
    cout << "Leaderboard:\n";
    for (const auto &player : leaderboard)
    {
        cout << player.name << ": " << player.score << "\n";
    }
}

// Function to sort the leaderboard in descending order based on score
void sortLeaderboard(vector<Player> &leaderboard)
{
    for (size_t i = 0; i < leaderboard.size(); ++i)
    {
        for (size_t j = i + 1; j < leaderboard.size(); ++j)
        {
            // Swap if the current player's score is less than the next player's score
            if (leaderboard[i].score < leaderboard[j].score)
            {
                swap(leaderboard[i], leaderboard[j]);
            }
        }
    }
}

int main()
{
    // Create a vector of players and their scores
    vector<Player> leaderboard = {
        {"Alice", 150},
        {"Bob", 200},
        {"Charlie", 175},
        {"David", 120}};

    // Sort the leaderboard by score in descending order
    sortLeaderboard(leaderboard);

    // Display the sorted leaderboard
    displayLeaderboard(leaderboard);

    return 0;
}
