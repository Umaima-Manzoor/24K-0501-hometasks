#include <iostream>
using namespace std;

class Box {
    private:
        int* volume;

    public:
        Box() : volume(0) {}

        Box(int v) {
            volume = new int(v);
        }

        Box(const Box& other) {
            volume = new int(*(other.volume));
        }

        void setVolume(int v) {
            *volume = v;
        }

        void displayInfo() {
            cout << "Volume: " << *volume << endl<<endl;
        }
};

int main() {
    Box b1(19);
    cout << "Box 1:" << endl;
    b1.displayInfo();

    Box b2 = b1;
    cout << "Box 2 Before Changing the Value: " << endl;
    b2.displayInfo();

    b2.setVolume(37);
    cout << "Box 2 After Changing the Value: " << endl;
    b2.displayInfo();

    cout << "Box 1 After Changing the Value of Box 2: " << endl;
    b1.displayInfo();

    return 0;
}


