#include <iostream>
#include <string>
using namespace std;

// Cargo class handles fare calculation and destination logic
class Cargo
{
private:
    string destination_city;
    int weight;
    int fare;
    string zone;

public:
    // Constructor to initialize the Cargo object
    Cargo() : destination_city(""), weight(0), fare(0), zone("") {}

    // Function to display menu
    void display_menu()
    {
        cout << "\n===== Cargo Transportation System =====\n";
        cout << "1. Select Destination\n";
        cout << "2. Enter Weight\n";
        cout << "3. Calculate Fare\n";
        cout << "4. Exit\n";
        cout << "Please select an option: ";
    }

    // Function to select destination city and determine zone
    void select_destination()
    {
        cout << "Select destination city:\n";
        cout << "1. Lahore\n";
        cout << "2. Islamabad\n";
        cout << "3. Karachi\n";
        cout << "4. Abbottabad\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            destination_city = "Lahore";
            zone = "Zone A";
            break;
        case 2:
            destination_city = "Islamabad";
            zone = "Zone A";
            break;
        case 3:
            destination_city = "Karachi";
            zone = "Zone C";
            break;
        case 4:
            destination_city = "Abbottabad";
            zone = "Zone B";
            break;
        default:
            cout << "Invalid city selection. Please try again.\n";
            select_destination(); // Recursive call for invalid input
        }
        cout << "You selected " << destination_city << " (" << zone << ").\n";
    }

    // Function to input weight
    void input_weight()
    {
        cout << "Enter the weight of the luggage (in Kg): ";
        cin >> weight;
        if (weight < 0)
        {
            cout << "Invalid weight. Please enter a positive value.\n";
            input_weight(); // Recursive call for invalid input
        }
    }

    // Function to calculate the fare based on the destination zone and weight
    void calculate_fare()
    {
        if (destination_city == "")
        {
            cout << "Please select a destination first.\n";
            return;
        }
        if (weight == 0)
        {
            cout << "Please enter the weight first.\n";
            return;
        }

        if (zone == "Zone A")
        {
            if (weight < 2)
                fare = 150;
            else if (weight <= 5)
                fare = 150 + 50 * (weight - 2);
            else
                fare = 400 + 25 * (weight - 5);
        }
        else if (zone == "Zone B")
        {
            if (weight < 2)
                fare = 200;
            else if (weight <= 5)
                fare = 200 + 75 * (weight - 2);
            else
                fare = 575 + 50 * (weight - 5);
        }
        else if (zone == "Zone C")
        {
            if (weight < 2)
                fare = 250;
            else if (weight <= 5)
                fare = 250 + 100 * (weight - 2);
            else
                fare = 750 + 75 * (weight - 5);
        }

        cout << "The fare for " << destination_city << " (weight: " << weight << " Kg) is: " << fare << " units.\n";
    }
};

// Main program to run the menu and interact with the user
int main()
{
    Cargo cargo;
    int choice;

    do
    {
        cargo.display_menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cargo.select_destination();
            break;
        case 2:
            cargo.input_weight();
            break;
        case 3:
            cargo.calculate_fare();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != 4);

    return 0;
}
