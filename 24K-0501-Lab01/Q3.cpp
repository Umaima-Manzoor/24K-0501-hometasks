#include <iostream>
using namespace std;

class Exam {
    private:
        int* marks;

   public:
        Exam(int v) {
            marks = new int(v);
        }

        void displayInfo() {
            cout << "Marks: " << *marks << endl;
        }

        void setMarks(int v) {
            *marks = v;
        }
};

int main() {
    Exam e1(98);

    cout << "Exam 1: " << endl;
    e1.displayInfo();   

    Exam e2 = e1;
    cout << "Exam 2 Before Changing the Value: " << endl;    
    e2.displayInfo();

    e2.setMarks(87);
    cout << "Exam 2 After Changing the Value: " << endl;
    e2.displayInfo();

    cout << "Exam 1 After Changing the Value of Exam 2: " << endl;
    e1.displayInfo();

}
