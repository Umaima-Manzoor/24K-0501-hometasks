//Q5 part (i)

#include <iostream>
using namespace std;

bool isSafe(int arr[5][5], int x, int y, int n, int solved[5][5]) {
    if (x>=0 && y>=0 && x<n && y<n && arr[x][y]==1 && solved[x][y]==0) {
        return true;
    }

    return false;
}

int sol = 0;
bool Maze(int arr[5][5], int x, int y, int setX, int destY, int n, int solved[5][5]) {
    if (x==setX && y==destY) {
        solved[x][y] = 1;
        sol++;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<solved[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        solved[x][y] = 0;
        return false;
    }

    if (isSafe(arr, x, y, n , solved)) {
        solved[x][y] = 1;

        Maze(arr, x+1, y, setX, destY, n, solved);
        Maze(arr, x, y+1, setX, destY, n, solved);
        Maze(arr, x-1, y, setX, destY, n, solved);
        Maze(arr, x, y-1, setX, destY, n, solved);

        solved[x][y] = 0;
   
    }
    return false;
}


int main() {

    int arr[5][5] = { {1,1,1,0,1},
                      {0,1,0,1,1},
                      {1,1,1,1,0},
                      {0,1,0,1,1},
                      {1,1,1,0,1} };

    int solved[5][5] = {0};

    Maze(arr, 0, 0, 2, 2, 5, solved);
    cout<<"Total possible paths: "<<sol<<endl;
    return 0;
}
