#include <iostream>
#include <queue>
using namespace std;

class Customer
{
public:
    int arrival_time;
    int waiting_time;

    Customer(int arrival_time)
    {
        this->arrival_time = arrival_time;
        this->waiting_time = 0;
    }
};

class Server
{
public:
    bool is_busy;
    int transaction_time;

    Server()
    {
        is_busy = false;
        transaction_time = 0;
    }

    void start_transaction(int transaction_time)
    {
        is_busy = true;
        this->transaction_time = transaction_time;
    }

    void finish_transaction()
    {
        is_busy = false;
        transaction_time = 0;
    }

    bool is_available()
    {
        return !is_busy;
    }
};

int main()
{
    queue<Customer> customer_queue;
    Server cashier;
    int current_time = 0;
    int total_waiting_time = 0;
    int customer_count = 0;
    int simulation_time = 100;

    while (current_time < simulation_time)
    {
        // New customer arrives every 5 minutes
        if (current_time % 5 == 0)
        {
            customer_queue.push(Customer(current_time));
            customer_count++;
        }

        // If the server is available, serve the customer
        if (!cashier.is_busy && !customer_queue.empty())
        {
            Customer current_customer = customer_queue.front();
            customer_queue.pop();
            current_customer.waiting_time = current_time - current_customer.arrival_time;
            total_waiting_time += current_customer.waiting_time;

            cashier.start_transaction(5); // 5 minutes to serve each customer
        }

        // Check if transaction is complete
        if (cashier.is_busy)
        {
            cashier.transaction_time--;
            if (cashier.transaction_time == 0)
            {
                cashier.finish_transaction();
            }
        }

        // Increment time
        current_time++;
    }

    cout << "Average waiting time: " << (double)total_waiting_time / customer_count << " minutes" << endl;
    return 0;
}
