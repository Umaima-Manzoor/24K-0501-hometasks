#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
    private:
        string* authors;
        int size;

    public:


        ResearchPaper() {
            cout << "Enter the number of authors you would like to add: ";
            cin >> size;
            authors = new string[size];
            cin.ignore();
            for (int i = 0; i < size; i++) {
                cout << "Enter author " << (i + 1) << ": ";
                getline(cin, authors[i]);
            }
        }

        ~ResearchPaper() {
            delete[] authors;
        }

        ResearchPaper(const ResearchPaper& other) {
            size = other.size;
            authors = new string[size];
            for (int i = 0; i < size; i++) {
                authors[i] = other.authors[i];
            }
        }

        ResearchPaper& operator=(const ResearchPaper& other) {
            if (this != &other) {
                size = other.size;
                authors = new string[size];
                for (int i = 0; i < size; i++) {
                    authors[i] = other.authors[i];
                }
            }
            return *this;
        }

        void displayInfo() {
            cout << "All the authors of the research paper: " << endl;
            for (int i = 0; i < size; i++) {
                cout << authors[i] << endl;
            }
            cout << endl;
        }

        void setAuthor(string a, int index) {
            if (index<=size) {
                authors[index] = a;
            }
            else {
                cout << "Index out of bounds " << endl;
            }
        }


};

int main() {
    ResearchPaper r1;
    cout << "Research Paper 1: " << endl;
    r1.displayInfo();

    ResearchPaper r2 = r1;
    cout << "Research Paper 2 (Copied from Research Paper 1 Usign Copy Constructor): " << endl;
    r2.displayInfo();

    ResearchPaper r3;
    cout << "Research Paper 3 before Assignment Operator: " << endl;
    r3.displayInfo();
    r3 = r2;
    cout << "Research Paper 3 (Copied from Research Paper 2 Using Assigmnent Operator): " << endl;
    r3.displayInfo();

    cout << "Changing an author of Research Paper 2: "<<endl;
    r2.setAuthor("New Name", 1);
    r2.displayInfo();

    cout << "Research Paper 1 After Changing an Author of Research Paper 2: "<<endl;
    r1.displayInfo();

    cout << "Research Paper 3 After Changing an Author of Research Paper 2: "<<endl;
    r3.displayInfo();


    return 0;
}
