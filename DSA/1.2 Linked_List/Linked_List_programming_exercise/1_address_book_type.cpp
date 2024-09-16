#include <iostream>
#include <string>
using namespace std;

// Define the structure for each entry in the address book
struct AddressBookEntry
{
    string name;
    string phone;
    string email;
    AddressBookEntry *next;

    AddressBookEntry(string n, string p, string e)
    {
        name = n;
        phone = p;
        email = e;
        next = nullptr;
    }
};

// AddressBook class to handle all operations
class AddressBook
{
private:
    AddressBookEntry *head;

public:
    // Constructor to initialize an empty list
    AddressBook()
    {
        head = nullptr;
    }

    // Function to add a new entry
    void addEntry(string name, string phone, string email)
    {
        AddressBookEntry *newEntry = new AddressBookEntry(name, phone, email);

        if (!head)
        {
            head = newEntry;
        }
        else
        {
            AddressBookEntry *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newEntry;
        }

        cout << "Entry added successfully!\n";
    }

    // Function to delete an entry by name
    void deleteEntry(string name)
    {
        if (!head)
        {
            cout << "Address book is empty.\n";
            return;
        }

        // If the entry to be deleted is the head
        if (head->name == name)
        {
            AddressBookEntry *temp = head;
            head = head->next;
            delete temp;
            cout << "Entry deleted successfully.\n";
            return;
        }

        AddressBookEntry *current = head;
        AddressBookEntry *previous = nullptr;

        while (current != nullptr && current->name != name)
        {
            previous = current;
            current = current->next;
        }

        if (!current)
        {
            cout << "Entry not found.\n";
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Entry deleted successfully.\n";
    }

    // Function to display all entries
    void displayEntries()
    {
        if (!head)
        {
            cout << "Address book is empty.\n";
            return;
        }

        AddressBookEntry *temp = head;
        cout << "Address Book Entries:\n";
        while (temp != nullptr)
        {
            cout << "Name: " << temp->name << "\n";
            cout << "Phone: " << temp->phone << "\n";
            cout << "Email: " << temp->email << "\n";
            cout << "----------------------\n";
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~AddressBook()
    {
        while (head != nullptr)
        {
            AddressBookEntry *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    AddressBook addressBook;
    int choice;
    string name, phone, email;

    do
    {
        cout << "\nAddress Book Menu:\n";
        cout << "1. Add Entry\n";
        cout << "2. Delete Entry\n";
        cout << "3. Display Entries\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore any newline character from previous input

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter phone: ";
            getline(cin, phone);
            cout << "Enter email: ";
            getline(cin, email);
            addressBook.addEntry(name, phone, email);
            break;

        case 2:
            cout << "Enter name to delete: ";
            getline(cin, name);
            addressBook.deleteEntry(name);
            break;

        case 3:
            addressBook.displayEntries();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
