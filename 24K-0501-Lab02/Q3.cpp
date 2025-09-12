#include <iostream>
using namespace std;

int main() {
    int row;
    
    cout << "How many teams?: ";
    cin >> row;

    int** arr = new int* [row];
    int size[row];

    for (int i=0;i<row; i++) {
        cout << "Enter the size of team "<< i+1<<": ";
        cin >>size[i];
        arr[i] = new int [size[i]];
    } 

    for (int i=0; i<row; i++) {
        cout << "Enter scores for team "<< i+1<<": "<<endl;
        for (int j=0; j<size[i]; j++) {
            cout << "Score "<< j+1<<": ";
            cin >> arr[i][j];
        }
    }

    cout << "Displaying the scores of teams: "<<endl;
    for (int i=0; i<row; i++) {
        cout << "Team "<< i+1<<":\t\t";
        for (int j=0; j<size[i]; j++) {
            cout << arr[i][j]<< "  ";
        }
        cout << endl;
    }
    
    cout << "Displaying cummulative scores of each team:"<<endl;
    
    
    for (int i=0; i<row; i++) {
        int total = 0;
        for (int j=0; j<size[i]; j++) {
            total += arr[i][j];
        }
        cout << "Team "<< i+1<<":\t\t"<<total<<endl;
        
    }
    
    
    
        for (int i=0; i<row; i++) {
            delete[] arr[i];
        }
    
        delete[] arr;
    
    
    return 0;
}
