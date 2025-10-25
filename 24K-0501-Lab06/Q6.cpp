/*Queue is the ideal data structure for the restaurant since is a FIFO structure (First-In First-Out) so the orders will be processed in the same order they are received

For addind orders, there will be two things that will be taken as input for each order from the user: 
1. Item name
2. Quantity

for orders, we will create a separate class named 'Order' to store the item name and quantity for each order. The Queue will then store objects of this Order class.

and when dequeuing an order, the system will remove the order at the front of the queue and process it. This ensures that orders are handled in the order they were received, maintaining fairness and efficiency in the restaurant's order processing system.

We will use dynamic array so that there won't be any overflow issue, and for underflow, we will check if the queue is empty before dequeuing an order. If the queue is empty, we will display a message indicating that there are no orders to process.
If the queue is full, we will display a message indicating that no more orders can be added at the moment.

For printing out all the processed orders, we will display the queue from front to rear, showing all the orders that are currently in the queue waiting to be processed in the order they are received to ensure that the restaurant staff can efficiently manage and fulfill customer orders.
*/

 #include <iostream>
using namespace std;


class Order {
    public:
        string itemName;
        int quantity;

        Order() : itemName(""), quantity(0) {}
        Order(string name, int qty) : itemName(name), quantity(qty) {}
};

class Queue {
    int front, rear, size;
    Order* arr;

    public:
        Queue(int n) {
            size = n;
            front = -1;
            rear = -1;
            arr = new Order[size];
        }

        bool isFull() {
            if ((rear + 1) % size == front) {
                return true;
            } else {
                return false;
            }
        }

        bool isEmpty() {
            if ((front == -1 && rear == -1) ) {
                return true;
            } else {
                return false;
            }
        }

        void enqueue(string itemName, int quantity) {
            if (isFull()) {
                cout << "Queue is full, cannot add more orders." << endl<<endl;
                return;
            }
            if (isEmpty()) {
                rear = front = 0;
            }
            else {
                rear = (rear + 1) % size;
                
            }
            arr[rear] = Order(itemName, quantity);
            cout << "Order added: " << itemName << " (Quantity: " << quantity << ")" << endl << endl;
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty, no orders to process." << endl << endl;
                return;
            }
            cout << "Processing order: " << arr[front].itemName << " (Quantity: " << arr[front].quantity << ")" << endl << endl;
            if (front == rear) {
                front = rear = -1; 
            } else {
                front = (front + 1) % size;
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "No orders in the queue." << endl << endl;
                return;
            }
            cout << "Current orders in the queue:" << endl;
            int i = front;
            while (true) {
                cout << "- " << arr[i].itemName << " (Quantity: " << arr[i].quantity << ")" << endl;
                if (i == rear) {
                    break;
                }
                i = (i + 1) % size;
            }
            cout << endl;
        }
};


int main() {
    
    Queue oq(5);
    oq.enqueue("Burger", 2);
    oq.enqueue("Pizza", 1);
    oq.enqueue("Pasta", 3);
    oq.display();


    oq.dequeue();
    oq.display();

    oq.enqueue("Salad", 1);
    oq.enqueue("Soda", 4);
    oq.enqueue("Ice Cream", 2);
    oq.display();

    cout << "Attempting to add another order (should fail):" << endl;
    oq.enqueue("Fries", 2);
    oq.display();

    cout << "Displaying remaining orders:" << endl;
    oq.display();

    oq.dequeue();

    cout << "Processing all remaining orders:" << endl;
    while (!oq.isEmpty()) {
        oq.dequeue();
    }

    cout << "Final state of the order queue:" << endl;
    oq.display();
    
    


    return 0;
}


