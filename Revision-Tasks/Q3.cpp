#include <iostream>
using namespace std;

bool isSafe(int arr[4][4], int x, int y, int n, int solved[4][4]) {
    if (x>=0 && y>=0 && x<n && y<n && arr[x][y]==1 && solved[x][y]==0) {
        return true;
    }

    return false;
}

bool Warehouse(int arr[4][4], int x, int y, int n, int solved[4][4]) {
    if (x==(n-1) && y==(n-1) ) {
        solved[x][y] = 1;
        return true;
    }


    if (isSafe(arr, x, y, n , solved)) {
        solved[x][y] = 1;

        if (Warehouse(arr, x+1, y, n, solved)) {
            return true;
        }
        if (Warehouse(arr, x, y+1, n, solved)) {
            return true;
        }
        if (Warehouse(arr, x-1, y, n, solved)) {
            return true;
        }
        if (Warehouse(arr, x, y-1, n, solved)) {
            return true;
        }

        solved[x][y] = 0;
        return false;
    }
    return false;
}


int main() {
    
    int grid[4][4] = { {1,0,1,1},
                       {1,1,0,1},
                       {0,1,1,1},
                       {1,0,1,1} };


    int solved[4][4] = {0};

    if (Warehouse(grid, 0, 0, 4,solved)) {
        cout << "Path for the robot:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << solved[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found for the robot" << endl;
    }


    return 0;
}

/*
(a) Backtracking Trace (Dry-Run):

1:  Start at (0,0) (Can go there since it's 1)

2:  Right (0,1) → (Can't go there since it's 0)
    Down (1,0) → (Can go there since it's 1) 

3:  From (1,0):
    Right (1,1) → (Can go there since it's 1)

4:  From (1,1):
    Right (1,2) → (can't go there since it's 0)
    Down (2,1) → (Can go there since it's 1)

5:  From (2,1):
    Right (2,2) → (Can go there since it's 1)

6:  From (2,2):
    Right (2,3) → (Can go there since it's 1)

7:  From (2,3):
    Down (3,3) → (Can go there since it's 1 and it's the destination)

Final Path (coordinates):
(0,0) → (1,0) → (1,1) → (2,1) → (2,2) → (2,3) → (3,3)



(b)
If multiple paths exist, the function follows a fixed order of moves here which is: Down, Right, Up, Left. 
This means that the function will always try to move down first, then right, then up, and finally left.
Therefore, if there are multiple valid paths to the destination, the function will return the first path it finds based on this order of exploration.
If a move leads to a dead end, the function backtracks and tries the next possible move in the order until it either finds a path to the destination or exhausts all possibilities.




*/

