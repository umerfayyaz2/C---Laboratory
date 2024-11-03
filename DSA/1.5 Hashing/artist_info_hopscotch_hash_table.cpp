#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

const int TABLE_SIZE = 17;  // Example size for hash table; adjust as needed
const int HOP_DISTANCE = 4; // Defines the neighborhood for hopscotch hashing

// Struct to store artist information
struct ArtistInfo
{
    int artist_id;
    string name;
    string genre;
    bool occupied; // Indicates if this slot is occupied

    ArtistInfo() : artist_id(-1), name(""), genre(""), occupied(false) {}
};

// Hopscotch Hash Table Class
class HopscotchHashTable
{
private:
    vector<ArtistInfo> table;

    // Hash function for an artist ID
    int hash(int artist_id)
    {
        return artist_id % TABLE_SIZE;
    }

public:
    HopscotchHashTable() : table(TABLE_SIZE) {}

    // Add new artist data
    bool addArtistInfo(int artist_id, const string &name, const string &genre)
    {
        int index = hash(artist_id);
        int start_index = index;

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (!table[index].occupied)
            {
                table[index] = {artist_id, name, genre, true};
                return true;
            }

            int current_dist = abs(index - start_index);
            if (current_dist < HOP_DISTANCE)
            {
                index = (index + 1) % TABLE_SIZE; // Linear probing
            }
            else
            {
                cerr << "Error: Could not add artist due to displacement limit. Rehash may be needed." << endl;
                return false;
            }
        }
        return false;
    }

    // Retrieve artist data by artist ID
    pair<string, string> getArtistInfo(int artist_id)
    {
        int index = hash(artist_id);

        for (int i = 0; i < HOP_DISTANCE; i++)
        {
            int current_index = (index + i) % TABLE_SIZE;
            if (table[current_index].occupied && table[current_index].artist_id == artist_id)
            {
                return {table[current_index].name, table[current_index].genre};
            }
        }
        return {"Not Found", "Not Found"};
    }

    // Update artist data if exists
    bool updateArtistInfo(int artist_id, const string &new_name, const string &new_genre)
    {
        int index = hash(artist_id);

        for (int i = 0; i < HOP_DISTANCE; i++)
        {
            int current_index = (index + i) % TABLE_SIZE;
            if (table[current_index].occupied && table[current_index].artist_id == artist_id)
            {
                table[current_index].name = new_name;
                table[current_index].genre = new_genre;
                return true;
            }
        }
        cerr << "Error: Artist ID not found for update." << endl;
        return false;
    }
};

int main()
{
    HopscotchHashTable artistTable;

    // Adding artist information
    artistTable.addArtistInfo(101, "Taylor Swift", "Pop");
    artistTable.addArtistInfo(102, "Ed Sheeran", "Pop");
    artistTable.addArtistInfo(103, "Drake", "Hip-Hop");
    artistTable.addArtistInfo(104, "Adele", "Soul");

    // Retrieving artist information
    auto artist = artistTable.getArtistInfo(103);
    cout << "Artist ID 103: " << artist.first << ", Genre: " << artist.second << endl;

    // Updating artist information
    artistTable.updateArtistInfo(101, "Taylor Swift", "Country/Pop");

    // Verifying update
    artist = artistTable.getArtistInfo(101);
    cout << "Artist ID 101: " << artist.first << ", Genre: " << artist.second << endl;

    return 0;
}