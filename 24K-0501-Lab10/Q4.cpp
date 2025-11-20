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


void minHeapify(int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left<num && heap[left] < heap[smallest])
        smallest = left;
    if (right <num && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(smallest);
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
    while (i!=0 && heap[parent(i)] > heap[i]) {
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

    minHeapify(0);
}



int main() {
    insert(100);
    insert(50);
    insert(75);
    insert(60);
    cout << "Initial heap:"<<endl;
    displayHeap();
    
    insert(55);
    cout << "After adding 55:"<<endl;
    displayHeap();

    remove();
    cout << "After removing the lowest price order:"<<endl;
    displayHeap();

    return 0;
}
