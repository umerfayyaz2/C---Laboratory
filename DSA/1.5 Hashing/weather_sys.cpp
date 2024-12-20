#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Class to represent weather data
class WeatherData
{
public:
    float temperature; // Temperature in Celsius
    string condition;  // Weather condition (e.g., Sunny, Rainy, Cloudy)

    // Constructor
    WeatherData(float temp, const string &cond) : temperature(temp), condition(cond) {}

    // Display weather information
    void display() const
    {
        cout << "Temperature: " << temperature << "°C, Condition: " << condition << endl;
    }
};

// WeatherSystem class for managing weather updates
class WeatherSystem
{
private:
    unordered_map<string, WeatherData> city_weather; // Hash map to store weather data by city

public:
    // Function to add or update weather data for a city
    void update_weather(const string &city, float temperature, const string &condition)
    {
        city_weather[city] = WeatherData(temperature, condition);
        cout << "Weather updated for city: " << city << endl;
    }

    // Function to get weather data for a city
    void get_weather(const string &city) const
    {
        auto i = city_weather.find(city);
        if (i != city_weather.end())
        {
            cout << "Weather in " << city << ": ";
            it->second.display();
        }
        else
        {
            cout << "Weather data for " << city << " not found." << endl;
        }
    }

    // Function to display all cities and their weather data
    void display_all_weather() const
    {
        if (city_weather.empty())
        {
            cout << "No weather data available." << endl;
            return;
        }

        cout << "Weather Data for All Cities:" << endl;
        for (const auto &entry : city_weather)
        {
            cout << entry.first << ": ";
            entry.second.display();
        }
    }
};

// Main function to test the WeatherSystem
int main()
{
    WeatherSystem system;

    // Adding weather data
    system.update_weather("New York", 25.5, "Sunny");
    system.update_weather("London", 15.3, "Cloudy");
    system.update_weather("Dubai", 40.1, "Hot");

    // Retrieving weather data
    cout << "\nRetrieve Weather Data:" << endl;
    system.get_weather("London");
    system.get_weather("Paris"); // City not added yet

    // Display all weather data
    cout << "\nAll Weather Data:" << endl;
    system.display_all_weather();

    // Update existing city data
    cout << "\nUpdating Weather Data:" << endl;
    system.update_weather("New York", 22.0, "Partly Cloudy");
    system.get_weather("New York");

    return 0;
}
