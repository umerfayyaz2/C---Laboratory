#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Class to represent a User
class User
{
private:
    string username;
    string phoneNumber;

public:
    // Constructor to initialize the User
    User(string name, string phone) : username(name), phoneNumber(phone) {}

    // Getter for username
    string getUsername() const
    {
        return username;
    }

    // Getter for phone number
    string getPhoneNumber() const
    {
        return phoneNumber;
    }

    // Setter for phone number
    void setPhoneNumber(string newPhone)
    {
        phoneNumber = newPhone;
    }
};

// Class to manage phonebook and notifications
class PhoneBook
{
private:
    unordered_map<string, User *> users;                 // Mapping phone numbers to Users
    unordered_map<string, vector<User *>> phoneContacts; // Mapping old phone numbers to users who have it

public:
    // Method to add a new user to the phonebook
    void addUser(User *user)
    {
        string phone = user->getPhoneNumber();
        if (users.find(phone) == users.end())
        {
            users[phone] = user;
        }
    }

    // Method to change a user's phone number and notify contacts
    void changePhoneNumber(User *user, string newPhone)
    {
        string oldPhone = user->getPhoneNumber();

        // Update user's phone number
        user->setPhoneNumber(newPhone);

        // Update phoneContacts mapping for the old phone number
        if (phoneContacts.find(oldPhone) != phoneContacts.end())
        {
            for (User *contact : phoneContacts[oldPhone])
            {
                cout << "Notifying " << contact->getUsername() << " about the phone number change of "
                     << user->getUsername() << " from " << oldPhone << " to " << newPhone << endl;
            }
        }

        // Update phoneContacts mapping for the new phone number
        phoneContacts[newPhone].push_back(user);

        // Remove old phone number from users
        users.erase(oldPhone);

        // Add new phone number to users map
        users[newPhone] = user;
    }

    // Method to display all users in the phonebook
    void displayUsers()
    {
        cout << "Users in the phonebook: \n";
        for (auto &entry : users)
        {
            cout << entry.second->getUsername() << " - " << entry.first << endl;
        }
    }
};

int main()
{
    // Create users
    User *user1 = new User("Alice", "123-456-7890");
    User *user2 = new User("Bob", "987-654-3210");
    User *user3 = new User("Charlie", "123-456-7890");

    // Create a phonebook
    PhoneBook phonebook;

    // Add users to the phonebook
    phonebook.addUser(user1);
    phonebook.addUser(user2);
    phonebook.addUser(user3);

    // Display users before the phone number change
    phonebook.displayUsers();

    // Change phone number of Alice and notify contacts
    phonebook.changePhoneNumber(user1, "111-222-3333");

    // Display users after the phone number change
    phonebook.displayUsers();

    // Clean up memory
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
