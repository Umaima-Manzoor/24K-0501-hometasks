#include <iostream>
using namespace std;

int capacity = 5;
int heap[5];
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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void maxHeapify(int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left<num && heap[left] > heap[largest])
        largest = left;
    if (right <num && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
}



void insert(int val) {
    if (num==capacity) {
        cout << "Heap is full!" <<endl;
        return;
    }
    heap[num] = val;
    num++;

    int i=num -1;
    while (i!=0 && heap[parent(i)] < heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}


void displayHeap() {
    cout << "Heap: [";
    for (int i = 0; i < num; i++) {
        cout << heap[i];
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
    insert(11);
    insert(5);
    insert(1);
    cout << "Initial heap:"<<endl;
    displayHeap();
    
    insert(10);
    cout << "After adding 10:"<<endl;
    displayHeap();

    remove();
    cout << "After removing highest priority:"<<endl;
    displayHeap();

    return 0;
}
