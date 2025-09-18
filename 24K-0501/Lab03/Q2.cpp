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

        void DeleteFromFront() {
            if (head == NULL) {
                cout << "Shopping cart is empty" << endl;
                return;
            }
            string val = '"' + head->name  + '"' + " - $" + to_string(head->price);

            Node* temp = head;
            head = head->next;
            delete temp;

            cout << val << " removed from cart" << endl;
        }

        void searchByName(string value) {
            Node* temp = head;
            while(temp != NULL) {
                if (temp->name == value) {

                    string val = '"' + temp->name  + '"' + " - $" + to_string(temp->price);
                    cout << val << " found in the linked list" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << value << " not found in the linked list" << endl;

        }

        void searchByPosition(int pos) {
            Node* temp = head;
            int count = 0;
            while(temp != NULL) {
                if (count == pos) {

                    string val = '"' + temp->name  + '"' + " - $" + to_string(temp->price);
                    cout << val << " found at position " << pos << endl;
                    return;
                }
                count++;
                temp = temp->next;
            }
            cout << "Linked List is out of bounds" << pos << endl;

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

    c.AddAtEnd("keyboard", 80);

    cout << "\nUpdated shopping cart: " << endl;
    c.displayInfo();

    c.DeleteFromFront();
    cout << "\nUpdated shopping cart: " << endl;
    c.displayInfo();

    c.searchByName("Tablet");
    c.searchByPosition(3);

    c.displayInfo();


    return 0;
}
