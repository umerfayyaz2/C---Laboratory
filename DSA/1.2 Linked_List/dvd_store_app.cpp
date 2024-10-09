#include <iostream>
#include <string>
using namespace std;

class customerType
{
private:
    int customerID;    // Unique ID for the customer
    string firstName;  // Customer's first name
    string lastName;   // Customer's last name
    int numDVDsRented; // Number of DVDs the customer has rented

public:
    // Default constructor
    customerType() : customerID(0), firstName(""), lastName(""), numDVDsRented(0) {}

    // Parameterized constructor
    customerType(int id, string fName, string lName, int numDVDs)
        : customerID(id), firstName(fName), lastName(lName), numDVDsRented(numDVDs) {}

    // Set customer details
    void setCustomerDetails(int id, string fName, string lName, int numDVDs)
    {
        customerID = id;
        firstName = fName;
        lastName = lName;
        numDVDsRented = numDVDs;
    }

    // Get the customer ID
    int getCustomerID() const
    {
        return customerID;
    }

    // Get the full name of the customer
    string getFullName() const
    {
        return firstName + " " + lastName;
    }

    // Get the number of DVDs rented by the customer
    int getNumDVDsRented() const
    {
        return numDVDsRented;
    }

    // Increment the number of DVDs rented
    void rentDVD()
    {
        numDVDsRented++;
    }

    // Decrement the number of DVDs rented
    void returnDVD()
    {
        if (numDVDsRented > 0)
        {
            numDVDsRented--;
        }
        else
        {
            cout << "No DVDs to return!" << endl;
        }
    }

    // Display customer details
    void displayCustomerInfo() const
    {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << getFullName() << endl;
        cout << "Number of DVDs Rented: " << numDVDsRented << endl;
    }
};

class customerListType
{
private:
    vector<customerType> customerList; // Vector to store the list of customers

public:
    // Add a new customer to the list
    void addCustomer(const customerType &newCustomer)
    {
        customerList.push_back(newCustomer);
    }

    // Remove a customer by ID
    void removeCustomer(int id)
    {
        bool found = false;
        for (size_t i = 0; i < customerList.size(); i++)
        {
            if (customerList[i].getCustomerID() == id)
            {
                customerList.erase(customerList.begin() + i);
                found = true;
                cout << "Customer with ID " << id << " has been removed." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Customer with ID " << id << " not found." << endl;
        }
    }

    // Search for a customer by ID
    customerType *searchCustomer(int id)
    {
        for (size_t i = 0; i < customerList.size(); i++)
        {
            if (customerList[i].getCustomerID() == id)
            {
                return &customerList[i]; // Return pointer to the customer if found
            }
        }
        return nullptr; // Return nullptr if customer not found
    }

    // Display the list of all customers
    void displayAllCustomers() const
    {
        if (customerList.empty())
        {
            cout << "No customers in the list." << endl;
            return;
        }
        for (const auto &customer : customerList)
        {
            customer.displayCustomerInfo();
            cout << "-------------------------" << endl;
        }
    }
};

int main()
{
    // Create a customer list object
    customerListType dvdStore;

    // Create customers
    customerType customer1(101, "John", "Doe", 2);
    customerType customer2(102, "Jane", "Smith", 1);
    customerType customer3(103, "Alice", "Johnson", 0);

    // Add customers to the list
    dvdStore.addCustomer(customer1);
    dvdStore.addCustomer(customer2);
    dvdStore.addCustomer(customer3);

    // Display all customers
    cout << "All Customers:" << endl;
    dvdStore.displayAllCustomers();

    // Search for a customer
    int searchID = 102;
    customerType *customer = dvdStore.searchCustomer(searchID);
    if (customer)
    {
        cout << "Customer found:" << endl;
        customer->displayCustomerInfo();
    }
    else
    {
        cout << "Customer with ID " << searchID << " not found." << endl;
    }

    // Remove a customer
    dvdStore.removeCustomer(103);

    // Display all customers after removal
    cout << "\nAll Customers after removal:" << endl;
    dvdStore.displayAllCustomers();

    return 0;
}