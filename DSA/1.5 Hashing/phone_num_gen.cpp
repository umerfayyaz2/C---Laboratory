#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// Class to represent a numbering plan for a region
class NumberingPlan
{
private:
    string country;                // Country name
    string region;                 // Region name (e.g., city)
    string area_code;              // Area code for the region
    int local_number_length;       // Length of the local number
    set<string> generated_numbers; // To ensure unique phone numbers

public:
    // Constructor
    NumberingPlan(string country_name, string region_name, string code, int length)
        : country(move(country_name)), region(move(region_name)), area_code(move(code)), local_number_length(length) {}

    // Function to generate a specific number of phone numbers
    vector<string> generate_phone_numbers(int count)
    {
        vector<string> phone_numbers;
        int max_local_number = pow(10, local_number_length); // Maximum local number range

        for (int i = 0; i < max_local_number && phone_numbers.size() < count; i++)
        {
            string local_number = to_string(i);
            // Pad with leading zeros if the length is less than required
            while (local_number.length() < local_number_length)
            {
                local_number = "0" + local_number;
            }

            // Combine area code and local number
            string phone_number = area_code + local_number;

            // Ensure uniqueness
            if (generated_numbers.find(phone_number) == generated_numbers.end())
            {
                phone_numbers.push_back(phone_number);
                generated_numbers.insert(phone_number);
            }
        }
        return phone_numbers;
    }

    // Function to display details of the numbering plan
    void display_plan_details() const
    {
        cout << "Country: " << country << ", Region: " << region << ", Area Code: " << area_code
             << ", Local Number Length: " << local_number_length << endl;
    }
};

// Main function to test the implementation
int main()
{
    // Create numbering plans for different regions
    NumberingPlan pakistan_karachi("Pakistan", "Karachi", "+92-21", 7);
    NumberingPlan saudi_riyadh("Saudi Arabia", "Riyadh", "+966-11", 7);
    NumberingPlan uae_dubai("UAE", "Dubai", "+971-4", 6);

    // Display numbering plan details
    pakistan_karachi.display_plan_details();
    saudi_riyadh.display_plan_details();
    uae_dubai.display_plan_details();

    // Generate and display phone numbers for Karachi
    cout << "\nPhone Numbers for Karachi:" << endl;
    vector<string> karachi_numbers = pakistan_karachi.generate_phone_numbers(5);
    for (const string &number : karachi_numbers)
    {
        cout << number << endl;
    }

    // Generate and display phone numbers for Riyadh
    cout << "\nPhone Numbers for Riyadh:" << endl;
    vector<string> riyadh_numbers = saudi_riyadh.generate_phone_numbers(5);
    for (const string &number : riyadh_numbers)
    {
        cout << number << endl;
    }

    // Generate and display phone numbers for Dubai
    cout << "\nPhone Numbers for Dubai:" << endl;
    vector<string> dubai_numbers = uae_dubai.generate_phone_numbers(5);
    for (const string &number : dubai_numbers)
    {
        cout << number << endl;
    }

    return 0;
}
