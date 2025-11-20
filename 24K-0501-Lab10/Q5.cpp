#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int v) : value(v), next(NULL){}
};

class PQueue {
    public:
        Node* front;

        PQueue() : front(NULL) {}
        ~PQueue() {
            while (front) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        void insert(int val) {
            Node* n = new Node(val);
            if (!front || val > front->value) {
                n->next = front;
                front = n;
            }
            else {
                Node* temp = front;
                while (temp->next && temp->next->value >= val) {
                    temp = temp->next;
                }
                n->next = temp->next;
                temp->next = n;
            }
        }

        void remove() {
            if (!front) {
                cout << "Queue is empty!"<<endl;
                return ;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        void print() {
            if (!front) {
                cout << "Queue is empty!"<<endl;
                return;
            }

            Node* temp = front;
            cout << "Player Queue: [";
            while (temp) {
                cout << temp->value;  
                if (temp->next) cout << ", ";
                temp = temp->next;
            }
            cout << "]" << endl;
        }
};

int main() {
    PQueue pq;

    pq.insert(1500);
    pq.insert(1200);
    pq.insert(1800);
    pq.insert(1600);

    cout << "Initial heap/queue:"<<endl;
    pq.print();

    pq.insert(1700);
    cout << "After adding 1700:"<< endl;
    pq.print();

    pq.remove();
    cout << "After removing highest rating:"<<endl;
    pq.print();


    return 0;
}
