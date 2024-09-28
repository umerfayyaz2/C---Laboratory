#include <iostream>
#include <queue>
using namespace std;

// Class to represent a customer
class Customer
{
public:
    int arrival_time; // Time when the customer arrives
    int service_time; // Time needed to serve the customer

    Customer(int arrival, int service)
    {
        arrival_time = arrival;
        service_time = service;
    }
};

int main()
{
    queue<Customer> customer_queue;
    int current_time = 0;        // Current time in the simulation
    int service_end_time = 0;    // Time when cashier will finish serving the current customer
    int total_wait_time = 0;     // Total wait time for all customers
    int number_of_customers = 5; // Number of customers to simulate

    // Adding customers to the queue (example: each arrives at different times)
    customer_queue.push(Customer(1, 3)); // Arrives at time 1, needs 3 minutes of service
    customer_queue.push(Customer(4, 2)); // Arrives at time 4, needs 2 minutes of service
    customer_queue.push(Customer(5, 4)); // Arrives at time 5, needs 4 minutes of service
    customer_queue.push(Customer(7, 1)); // Arrives at time 7, needs 1 minute of service
    customer_queue.push(Customer(8, 2)); // Arrives at time 8, needs 2 minutes of service

    // Simulate the process of serving the customers
    while (!customer_queue.empty())
    {
        Customer current_customer = customer_queue.front();

        // Serve the customer only when they arrive (current_time >= arrival_time)
        if (current_time >= current_customer.arrival_time)
        {
            cout << "Serving customer who arrived at time " << current_customer.arrival_time << endl;

            // Calculate waiting time (time the customer waited before being served)
            int wait_time = current_time - current_customer.arrival_time;
            total_wait_time += wait_time;

            // Serve the customer (service time)
            current_time += current_customer.service_time;
            service_end_time = current_time;

            // Remove the customer from the queue after serving
            customer_queue.pop();
        }
        else
        {
            // Move time forward if no customers to serve yet
            current_time++;
        }
    }

    cout << "Simulation finished!" << endl;
    cout << "Total wait time for all customers: " << total_wait_time << " minutes." << endl;
    cout << "Average wait time: " << (float)total_wait_time / number_of_customers << " minutes." << endl;
    return 0;
}
