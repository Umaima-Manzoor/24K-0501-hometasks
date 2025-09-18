#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string name;
        int price;
        Node* next;

        Node(string name, int price): name(name), price(price){}


        

};

class ShoppingCart {
    public:
        Node *head;
        Node *tail;

        ShoppingCart() : head(NULL), tail(NULL) {}

        void AddAtFront(string name, int price) {
            Node *n = new Node(name, price);
            if (head == NULL) {
                head = n;
                tail = n;

                string val = '"' + n->name  + '"' + " - $" + to_string(n->price);

                cout << val << " added to cart" << endl;
                return;
            }

            else {
                
                n->next = head;
                head = n;
                string val = '"' + n->name  + '"' + " - $" + to_string(n->price);

                cout << val << " added to cart" << endl;
            }
        }

        void AddAtEnd(string name, int price) {
            Node *n = new Node(name, price);
            if (head == NULL) {
                head = n;
                tail = n;

                string val = '"' + n->name  + '"' + " - $" + to_string(n->price);
                cout << val << " added to cart" << endl;
                return;
            }

            else {
                
                tail->next = n;
                tail = n;
                 string val = '"' + n->name  + '"' + " - $" + to_string(n->price);
                cout << val << " added to cart" << endl;
            }
        }

        void addAtPosition(string name, int price, int pos) {
            Node* n = new Node(name, price);
            Node *current;
            Node *previous;
            current = head;
            for (int i=0; i<pos; i++){
                previous = current;
                current = current->next;
            }
            previous->next = n;
            n->next = current;
            
             string val = '"' + n->name  + '"' + " - $" + to_string(n->price);
                cout << val << " added at position " << pos << endl;
        }

        void search(string val) {
            Node* temp = head;
            while(temp != NULL) {
                if (temp->name == val) {

                    string val = '"' + temp->name  + '"' + " - $" + to_string(temp->price);
                    cout << val << " found in the linked list" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << val << " not found in the linked list" << endl;

        }

        void displayInfo() {
            Node *temp = head;
            if (head == NULL) {
                cout << "Shopping cart is empty" << endl;
                return;
            }
            while (temp != NULL ){
                string val = '"' + temp->name  + '"' + " - $" + to_string(temp->price);
                cout << val << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl<<endl;
        }



        

};

int main() {
    ShoppingCart c;
    c.AddAtFront("Laptop", 1000);
    c.AddAtEnd("Phone", 700);
    c.AddAtEnd("Tablet", 400);
    c.AddAtEnd("Headphones", 150);

    cout << "\nInitial shopping cart: " << endl;
    c.displayInfo();

    c.AddAtFront("Smartwatch", 200);
    c.AddAtEnd("keyboard", 80);

    cout << "\nUpdated shopping cart: " << endl;
    c.displayInfo();

    c.addAtPosition("Monitor", 300, 3);

    cout << "\nUpdated shopping cart: " << endl;
    c.displayInfo();

    c.search("Tablet");

    c.displayInfo();


    return 0;
}
