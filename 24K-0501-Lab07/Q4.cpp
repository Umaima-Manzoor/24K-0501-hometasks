#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d = 0) : data(d), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insert(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* getTail(Node* cur) {
        while (cur != NULL && cur->next != NULL) {
            cur = cur->next;
        }
        return cur;
    }

    Node* partition(Node* start, Node* end) {
        int pivot = end->data;
        Node* i = start;
        Node* j = start;

        while (j != end) {
            if (j->data < pivot) {
                swap(i, j);
                i = i->next;
            }
            j = j->next;
        }

        swap(i, end);
        return i;
    }

    void quickSortRec(Node* start, Node* end) {
        if (start == NULL || start == end) {
            return;
        }

        Node* pivot = partition(start, end);

        if (pivot != start) {
            Node* temp = start;
            while (temp->next != pivot) {
                temp = temp->next;
            }
            quickSortRec(start, temp);
        }

        if (pivot->next != NULL) {
            quickSortRec(pivot->next, end);
        }
    }

    void quickSort() {
        Node* end = getTail(head);
        quickSortRec(head, end);
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of integers: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "Original Order:" << endl;
    list.display();

    list.quickSort();
    cout << "After Sorting:" << endl;
    list.display();

    return 0;
}
