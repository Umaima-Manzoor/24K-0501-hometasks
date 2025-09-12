#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



class Array {


    private:
        int** arr;
        int row, col;


    public:
        Array(int r, int c){
            row = r;
            col = c;
            arr = new int*[row];
            for (int i=0; i<row; i++) {
                arr[i] = new int[col];
                for (int j=0; j<col; j++) {
                    int num = rand() %10 + 1;
                    arr[i][j] = num;
                }
            }
        }

        ~Array() {
            for (int i=0; i<row ; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }

        void transpose() {
            int** trans = new int*[col];
            for (int i = 0; i < col; ++i) {
                trans[i] = new int[row];
                for (int j = 0; j < row; ++j) {
                    trans[i][j] = arr[j][i];
                }

            }

            for (int i = 0; i < row; ++i) {
                delete[] arr[i];
            }
            delete[] arr;

            arr = trans;
            int temp = row;
            row = col;
            col = temp;

            
        }

        void displayInfo() {
            cout << "Displaying matrix:"<<endl;
            for (int i=0; i<row; i++) {
                cout << "|\t";
                for (int j=0; j<col; j++) {
                    if ((j%2)== 0){
                        arr[i][j] += 2;
                    }
                    cout << arr[i][j]<< "\t|\t";
                }
                cout << endl;
            }
        }

        void resize(int newR, int newC) {
            int** newArr = new int*[newR];
            for (int i=0; i<newR; i++) {
                newArr[i] = new int[newC];
            }

            for (int i = 0; i < newR; ++i) {
                for (int j = 0; j < newC; ++j) {
                    if (i < row && j < col)
                        newArr[i][j] = arr[i][j];  
                    else
                        newArr[i][j] = -1;  
                }
            }

            for (int i = 0; i < row; ++i) {
                delete[] arr[i];
            }
            delete[] arr;

            arr = newArr;
            row = newR;
            col = newC;
        }

};


int main() {
     srand(time(0)); 
    Array a1(3, 2);
    a1.displayInfo();
    a1.transpose();
    cout << "Printing after transposing:"<<endl;
    a1.displayInfo();

    a1.resize(1,2);
    cout << "Printing after resizing (truncating):"<<endl;
    a1.displayInfo();

    return 0;
}
