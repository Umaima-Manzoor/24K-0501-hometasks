#include <iostream>
using namespace std;

bool isSafe(int arr[4][4], int x, int y, int n, int solved[4][4]) {
    if (x>=0 && y>=0 && x<n && y<n && arr[x][y] == 1 && solved[x][y]==0) {
        return true;
    }
    return false;
}


bool Building(int arr[4][4], int x, int y, int n, int solved[4][4]) {
    if (x==(n-1) && y==(n-1)) {
        solved[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, solved)) {
        solved[x][y] = 1;

        if (Building(arr, x+1, y, n, solved)) {
            return true;
        }
        if (Building(arr, x, y+1, n, solved)) {
            return true;
        }
        if (Building(arr, x-1, y, n, solved)) {
            return true;
        }
        if (Building(arr, x, y-1, n, solved)) {
            return true;
        }

        solved[x][y] = 0;
        return false;
    }
    return false;
}

int main() {

    int maze[4][4] = { {1,1,0,1},
                       {0,1,1,0},
                       {1,1,0,1},
                       {0,1,1,1} };

    int solved[4][4] = {0};


    if (Building(maze, 0, 0, 4, solved)) {
        cout << "Path for the person to escape the building:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << solved[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found for the person to escape the building" << endl;
    }

    return 0;
}


/*
(a) Backtracking Trace (Dry-Run):

1:  Start at (0,0) (Can go there since it's 1)

2:  From (0,0):
    Down (1,0) → (Can't go there since it's 0)
    Right (0,1) → (Can go there since it's 1)

3:  From (0,1):
    Down (1,1) → (Can go there since it's 1)

4:  From (1,1):
    Down (2,1) → (Can go there since it's 1)

5:  From (2,1):
    Down (3,1) → (Can go there since it's 1)

6:  From (3,1):
    Down (4,1) → (Out of bounds)
    Right (3,2) → (Can go there since it's 1)

7:  From (3,2):
    Down (4,2) → (Out of bounds)
    Right (3,3) → (Can go there since it's 1 and it's the destination)

Final Path (coordinates):
(0,0) → (0,1) → (1,1) → (2,1) → (3,1) → (3,2) → (3,3)


(b)
If no safe routes exist (if the person cannt escape the burning building), the algorithm will explore all possible paths and backtrack whenever it hits a dead end. If it exhausts all options without reaching the destination (n-1, n-1), it will return false, indicating that no path exists. The output will then state that no path was found for the person to escape the building.


*/
