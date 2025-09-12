#include <iostream>
using namespace std;

class Array {
    private:
        int* arr;
        int current_size, capacity;

    public:
        Array(int num){
            arr = new int[num];
            num = capacity;
            current_size = 0;
        }

        ~Array() {
            delete[] arr;
        }

        void push_back(int num) {
            if (current_size == capacity) {
                capacity *= 2;
                int* newArr = new int[capacity];
                for (int i=0; i>current_size; i++) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
               
            }

            else {
                arr[current_size++] = num;
            }
        }

        void displayInfo() {
            if (current_size ==0) {
                cout << "Empty array"<<endl;
                return;
            }
            cout << "Values in the array:"<<endl;
            for (int i=0; i<current_size; i++) {
                cout << arr[i]<<endl;
            }
            cout << endl;
        }

};

int main() {
    Array a1(2);
    a1.displayInfo();
    a1.push_back(3);
    a1.push_back(4);

    a1.displayInfo();
    a1.push_back(10);
    a1.push_back(12);

    a1.displayInfo();

    return 0;
}
