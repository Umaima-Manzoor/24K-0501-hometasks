#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int score;
    Node* next;

    Node(string n="", int s=0) : name(n), score(s), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    int num;

    LinkedList() : head(NULL), num(0) {}

    void insert(string name, int score) {
        Node* n = new Node(name, score);
        if (head == NULL) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != NULL){
                temp = temp->next;}
            temp->next = n;
        }
        num++;
    }

    int getMax() {
        int mx = head->score;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->score > mx){
                mx = temp->score;}
            temp = temp->next;
        }
        return mx;
    }

    void countSort(int exp) {
        int* outputScores = new int[num];
        string* outputNames = new string[num];
        int count[10] = {0};

        Node* temp = head;
        while (temp != NULL) {
            int digit = (temp->score / exp) % 10;
            count[digit]++;
            temp = temp->next;
        }

        for (int i = 1; i < 10; i++){
            count[i] += count[i - 1];}

        Node** nodes = new Node*[num];
        temp = head;
        for (int i = 0; i < num; i++) {
            nodes[i] = temp;
            temp = temp->next;
        }

        for (int i = num - 1; i >= 0; i--) {
            int digit = (nodes[i]->score / exp) % 10;
            outputScores[count[digit] - 1] = nodes[i]->score;
            outputNames[count[digit] - 1] = nodes[i]->name;
            count[digit]--;
        }

        temp = head;
        for (int i = 0; i < num; i++) {
            temp->score = outputScores[i];
            temp->name = outputNames[i];
            temp = temp->next;
        }

        delete[] outputScores;
        delete[] outputNames;
        delete[] nodes;
    }

    void radixSort() {
        if (head == NULL)
            return;

        int m = getMax();

        for (int exp = 1; m / exp > 0; exp *= 10){
            countSort(exp);}
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->name << " - " << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int num;
    cout << "Enter number of students: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        list.insert(name, score);
        cout << endl;
    }

    cout << "Before Sorting: " << endl;
    list.display();

    list.radixSort();
    cout << endl;

    cout << "After Sorting (Ascending by Score): " << endl;
    list.display();

    return 0;
}
