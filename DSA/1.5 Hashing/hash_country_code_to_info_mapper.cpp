#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Enum for country codes to simplify indexing
enum CountryCode
{
    PAK,
    SA,
    USA,
    UAE,
    UK,
    UNKNOWN
};

// Hash function to map country codes to indices
CountryCode hashCountryCode(const string &code)
{
    if (code == "PAK")
        return PAK;
    if (code == "SA")
        return SA;
    if (code == "USA")
        return USA;
    if (code == "UAE")
        return UAE;
    if (code == "UK")
        return UK;
    return UNKNOWN; // Default if the code is unknown
}

// Country information struct
struct CountryInfo
{
    string name;
    string iso_code;
    string currency;
    string capital;
};

// Perfect hash table for countries
CountryInfo countryTable[] = {
    {"Pakistan", "PAK", "PKR", "Islamabad"},             // PAK
    {"Saudi Arabia", "SA", "SAR", "Riyadh"},             // SA
    {"United States", "USA", "USD", "Washington D.C."},  // USA
    {"United Arab Emirates", "UAE", "AED", "Abu Dhabi"}, // UAE
    {"United Kingdom", "UK", "GBP", "London"}            // UK
};

// Function to retrieve country information using the hash table
CountryInfo get_country_info(const string &code)
{
    CountryCode index = hashCountryCode(code);
    if (index != UNKNOWN)
    {
        return countryTable[index];
    }
    else
    {
        // Return an empty entry if the code is unknown
        return {"Unknown", "N/A", "N/A", "N/A"};
    }
}

int main()
{
    // Test the system
    string codes[] = {"PAK", "SA", "USA", "UAE", "UK", "IND"};
    for (const string &code : codes)
    {
        CountryInfo info = get_country_info(code);
        cout << "Country Code: " << code << endl;
        cout << "Country: " << info.name << ", ISO Code: " << info.iso_code
             << ", Currency: " << info.currency << ", Capital: " << info.capital << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}
