#include <iostream>
using namespace std;

class Node {
    public:
        int itemID;
        string itemName;
        int itemPrice;
        Node* next;
        Node* prev;

        Node() : itemID(0),itemName(""), itemPrice(0), next(NULL), prev(NULL) {}
        Node(int id, string name, int price) : itemID(id),itemName(name), itemPrice(price), next(NULL), prev(NULL) {}
};

class Site {
    public:
    Node* head;
    Node* tail;

    Site() : head(NULL), tail(NULL) {}

    void AddAtEnd(int id, string name, int price) {
         Node* n = new Node(id, name, price);
        if (tail == NULL) {
            head = n;
            tail = n;
        
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }

        string val = "ID: " + to_string(n->itemID) + ", Name: " + n->itemName + ", Price: $" + to_string(n->itemPrice);
        cout << val << " added at end" << endl;
    }

    void AddAtFront(int id, string name, int price) {
         Node* n = new Node(id, name, price);
        if (head == NULL) {
            head = n;
            tail = n;
        
        }
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }

        string val = "ID: " + to_string(n->itemID) + ", Name: " + n->itemName + ", Price: $" + to_string(n->itemPrice);
        cout << val << " added at front" << endl;
    }

    void deleteFromFront() {
        
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int id = head->itemID;
        string name = head->itemName;
        int price = head->itemPrice;

        string val = "ID: " + to_string(id) + ", Name: " + name + ", Price: $" + to_string(price);

        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
        cout << val << " deleted from front" << endl;
        
    }

    void DeleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int id = tail->itemID;
        string name = tail->itemName;
        int price = tail->itemPrice;

        string val = "ID: " + to_string(id) + ", Name: " + name + ", Price: $" + to_string(price);

        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }
        cout << val << " deleted from end" << endl;
    }

    void searchByID(int id) {
        Node* temp = head;
        while(temp != NULL) {
            if (temp->itemID == id) {
                string val = "ID: " + to_string(temp->itemID) + ", Name: " + temp->itemName + ", Price: $" + to_string(temp->itemPrice);
                
                cout << val << " found in the linked list" << endl;
                return;
            }
            temp = temp->next;
        }
        cout  << "No item with ID "<< id << " found in the linked list" << endl;
    }

    void UpdatePriceByID(int id, int newPrice) {
        Node* temp = head;

        while(temp != NULL) {
            if (temp->itemID == id) {
                temp->itemPrice = newPrice;
                
                string val = "ID: " + to_string(temp->itemID) + ", Name: " + temp->itemName + ", Price: $" + to_string(temp->itemPrice);
                cout << val << " updated in the linked list" << endl;
                return;
            }
            temp = temp->next;
        }
        cout  << "No item with ID "<< id << " found in the linked list" << endl;
    }

    void displayFromFront() {
        Node *temp = head;
        while (temp != NULL ){
            string val = "ID: " + to_string(temp->itemID) + ", Name: " + temp->itemName + ", Price: $" + to_string(temp->itemPrice);
            cout << val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl<<endl;
        
    }

    void displayFromEnd() {
        Node *temp = tail;
        while (temp != NULL ){
            string val = "ID: " + to_string(temp->itemID) + ", Name: " + temp->itemName + ", Price: $" + to_string(temp->itemPrice);
            cout << val << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl<<endl;
        
    }

    int count() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void FindExpensive() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        Node* expensive = head;
        while (temp != NULL) {
            if (temp->itemPrice > expensive->itemPrice) {
                expensive = temp;
            }
            temp = temp->next;
        }
        string val = "ID: " + to_string(expensive->itemID) + ", Name: " + expensive->itemName + ", Price: $" + to_string(expensive->itemPrice);
        cout << "Most expensive item: " << val << endl;

    }
};

int main () {
    Site s;
    s.AddAtEnd(101, "Laptop", 1200);
    s.AddAtEnd(102, "Phone", 700);
    s.AddAtFront(100, "Tablet", 400);
    s.AddAtEnd(103, "Monitor", 150);
    s.AddAtFront(99, "Headphones", 100);
    s.AddAtEnd(104, "Keyboard", 80);

    cout << "Initial Linked List from front: " << endl;
    s.displayFromFront();

    s.deleteFromFront();
    cout << "Linked List after deleting from front: " << endl;
    s.displayFromFront();

    s.DeleteFromEnd();
    cout << "Linked List after deleting from end: " << endl;
    s.displayFromFront();

    s.searchByID(102);
    s.UpdatePriceByID(103, 350);
    cout << "\nLinked List after updating price: " << endl;

    cout << "Linked List from front: " << endl;
    s.displayFromFront();

    cout << "Linked List from end: " << endl;
    s.displayFromEnd();

    cout << "Total items in the list: " << s.count() << endl;
    s.FindExpensive();
    

    return 0;
}
