#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        int ID;
        string CustomerName;
        string RideName;
        Node* next;

        Node(int id, string customer, string ride): ID(id), CustomerName(customer), RideName(ride), next(NULL){}
};

class BookingSystem {
    public:
        Node* head;
        Node* tail;

        BookingSystem() : head(NULL), tail(NULL) {}

        
        void addAtEnd(int id, string customer, string ride) {
            Node* n = new Node(id, customer, ride);
            if (head == NULL) {
                head = n;
                n->next = head;
                tail = n;
                
                string val = "Booking ID: " + to_string(n->ID) + ", Customer: " + n->CustomerName + ", Ride: " + n->RideName;
                cout << val << " added at end" << endl;
                return;
            }

            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
                
            }
            
            temp->next = n;
            tail = n;
            tail->next = head;
            
            string val = "Booking ID: " + to_string(n->ID) + ", Customer: " + n->CustomerName + ", Ride: " + n->RideName;
            cout << val << " added at end" << endl;
        }

        void PriorityBooking(int id, string customer, string ride) {
            Node* n = new Node(id, customer, ride);
            if (head == NULL) {
                head = n;
                n->next = head;
                tail = n;
                
                string val = "Booking ID: " + to_string(n->ID) + ", Customer: " + n->CustomerName + ", Ride: " + n->RideName;
                cout << val << " added as priority booking" << endl;
                return;
            }

            n->next = head;
            head = n;
            tail->next = head;

            string val = "Booking ID: " + to_string(n->ID) + ", Customer: " + n->CustomerName + ", Ride: " + n->RideName;
            cout << val << " added as priority booking at the front" << endl;
        }

        void DeleteByID(int id) {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }

            Node* current = head;
            Node* prev = NULL;

            do {
                if (current->ID == id) {
                    string val = "Booking ID: " + to_string(current->ID) + ", Customer: " + current->CustomerName + ", Ride: " + current->RideName;
                    
                    if (current == head) {
                        if (head == tail) {
                            delete head;
                            head = NULL;
                            tail = NULL;
                        }
                        else {
                            head = head->next;
                            tail->next = head;
                            delete current;
                        }
                    }
                    else if (current == tail) {
                        tail = prev;
                        tail->next = head;
                        delete current;
                    }
                    else {
                        prev->next = current->next;
                        delete current;
                    }

                    cout << val << " deleted from list" << endl;
                    return;
                }
                prev = current;
                current = current->next;
            } while (current != head);
            cout  << "No ticket with ID "<< id << " found in the list" << endl;
            
            
        }

        void DeleteFromFront() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }

            int id = head->ID;
            string customer = head->CustomerName;
            string ride = head->RideName;

            string val = "Booking ID: " + to_string(id) + ", Customer: " + customer + ", Ride: " + ride;

            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else {
                Node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
                
            }
            cout << val << " deleted from front" << endl;
            
        }
        
        void searchByID(int id) {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }

            Node* temp = head;
            do {
                if (temp->ID == id) {
                    string val = "Booking ID: " + to_string(temp->ID) + ", Customer: " + temp->CustomerName + ", Ride: " + temp->RideName;
                    
                    cout << val << " found in the list" << endl;
                    return;
                }
                temp = temp->next;
            } while (temp != head);
          }
        
        
        void displayInfo() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            Node *temp = head;
            do {
                string val = "Booking ID: " + to_string(temp->ID) + ", Customer: " + temp->CustomerName + ", Ride: " + temp->RideName;
                cout << val << " -> ";
                temp = temp->next;
           } while (temp != head);
            
           cout << "(replaying the bookings from the start: Booking ID: " + to_string(head->ID) + ", Customer: " + head->CustomerName + ", Ride: " + head->RideName + ")" << endl<<endl;
         }
        

        void count() {
            Node* temp = head;
            int count = 0;

            if (head == NULL) {
                cout << "List is empty. Total bookings: " << count<< endl;
                return;
            }

            do {
            count++;
            temp = temp->next;
        } while (temp != head);
        cout << "Total bookings in the list: " << count << endl;
       
        }

        void NextTicket(int id) {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            do {
                if (temp->ID == id) {
                    string val = "Booking ID: " + to_string(temp->next->ID) + ", Customer: " + temp->next->CustomerName + ", Ride: " + temp->next->RideName;
                    
                    cout << "Next ticket after ID " << id << " is: " << val << endl;
                    return;
                }
                temp = temp->next;
            } while (temp != head);
            cout << "No ticket with ID " << id << " found in the list" << endl;
        }
       
};

int main() {
    BookingSystem b;
    b.addAtEnd(101, "Umaima", "Roller Coaster");
    b.addAtEnd(102, "Manzoor", "Ferris Wheel");
    b.addAtEnd(103, "Maria", "Haunted House");
    b.PriorityBooking(100, "VIP Ayesha", "Drop Tower");
    b.addAtEnd(104, "Zaid", "Bumper Cars");
    b.addAtEnd(105, "Mirha", "Log Slide");
    b.PriorityBooking(99, "VIP Ali", "Pendulum Ride");

    cout << "\nInitial booking list: " << endl;
    b.displayInfo();

    b.DeleteFromFront();
    cout << "\nUpdated booking list: " << endl;
    b.displayInfo();

    b.DeleteByID(103);
    cout << "\nUpdated booking list: " << endl;
    b.displayInfo();

    b.searchByID(104);

    b.displayInfo();
    b.count();
    b.NextTicket(105);


    return 0;

}
