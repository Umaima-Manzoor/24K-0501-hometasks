#include <iostream>
using namespace std;

struct Task {
	char letter;
	int priority;
};

int capacity = 5;
Task heap[5];
int num = 0;

int parent(int i) {
    return (i-1)/2;
}

int leftChild(int i) {
    return (2*i) + 1;
}

int rightChild(int i) {
    return (2*i) + 2;
}

void swap(Task &a, Task &b) {
    Task temp = a;
    a = b;
    b = temp;
}


void maxHeapify(int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left<num && heap[left].priority > heap[largest].priority)
        largest = left;
    if (right <num && heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
}



void insert(char name, int val) {
    if (num==capacity) {
        cout << "Heap is full!" <<endl;
        return;
    }
    heap[num] = {name, val};
    num++;

    int i=num -1;
    while (i!=0 && heap[parent(i)].priority < heap[i].priority) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}


void displayHeap() {
    cout << "Heap: [";
    for (int i = 0; i < num; i++) {
         cout << heap[i].letter << "(" << heap[i].priority << ")";
        if (i < num - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void remove() {
    if (num <=0) {
        cout << "Heap is empty!"<<endl;
        return;
    }
    if (num==1) {
        num--;
        return;
    }
    heap[0] = heap[num-1];
    num--;

    maxHeapify(0);
}

int main() {
    insert('A',5);
    insert('B', 3);
    insert('C',8);
    cout << "Initial heap:"<<endl;
    displayHeap();
    
    remove();
    cout << "After removing highest priority:"<<endl;
    displayHeap();

    insert('D',6);
    cout << "After adding D(6):"<<endl;
    displayHeap();


    return 0;
}
