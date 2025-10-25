#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

int front = -1;
int rear = -1;
string arr[MAX];

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(string name) {
    if (isFull()) {
        cout << "Queue is full, cannot add patron " << name << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    arr[++rear] = name;
    cout << name << " has joined the queue" << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty, no patrons to serve" << endl;
        return;
    }
    cout << arr[front] << "'s book transaction completed. Patron has left the queue" << endl;
    front++;
}

void display() {
    if (isEmpty()) {
        cout << "No patrons currently waiting." << endl;
        return;
    }
    cout << "Current patrons waiting in queue:" << endl;
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". " << arr[i] << endl;
    }
}

int main() {
    int choice;
    string name;

    do {
        cout << endl;
        cout << "===== Library Transaction Queue =====" << endl;
        cout << "1. Join queue as patron (Borrow/Return Books)" << endl;
        cout << "2. Complete transaction (Next Patron)" << endl;
        cout << "3. Show current queue (patrons in waiting)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patron name: ";
                cin >> name;
                enqueue(name);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "The patrons have left the library. Have a nice day!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
