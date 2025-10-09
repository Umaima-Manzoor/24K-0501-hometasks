#include <iostream>
using namespace std;

bool isSafe(int arr[5][5], int x, int y, int n, int solved[5][5]) {
    return (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1 && solved[x][y] == 0);
}

int solR = 0;
int solC = 0;

int RVisited[5][5] = {0};
int CVisited[5][5] = {0};


bool RabbitMaze(int arr[5][5], int x, int y, int destX, int destY, int n, int solved[5][5]) {
    if (x == destX && y == destY) {
        solved[x][y] = 1;
        solR++;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solved[i][j] << " ";
                if (solved[i][j] == 1) {
                    RVisited[i][j] = 1; 
        }
            }
            cout << endl;
        }
        cout << endl;

        solved[x][y] = 0; 
        return false;
    }

    if (isSafe(arr, x, y, n, solved)) {
        solved[x][y] = 1;

        RabbitMaze(arr, x + 1, y, destX, destY, n, solved);
        RabbitMaze(arr, x, y + 1, destX, destY, n, solved);
        RabbitMaze(arr, x - 1, y, destX, destY, n, solved);
        RabbitMaze(arr, x, y - 1, destX, destY, n, solved);

        solved[x][y] = 0;
    }
    return false;
}

bool CatMaze(int arr[5][5], int x, int y, int destX, int destY, int n, int solved[5][5]) {
    if (x == destX && y == destY) {
        solved[x][y] = 1;
        solC++;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solved[i][j] << " ";
                if (solved[i][j] == 1){ 
                    CVisited[i][j] = 1; }
                
            }
            cout << endl;
        }
        cout << endl;

        solved[x][y] = 0; 
        return false;
    }

    if (isSafe(arr, x, y, n, solved)) {
        solved[x][y] = 1;

        CatMaze(arr, x + 1, y, destX, destY, n, solved);
        CatMaze(arr, x, y + 1, destX, destY, n, solved);
        CatMaze(arr, x - 1, y, destX, destY, n, solved);
        CatMaze(arr, x, y - 1, destX, destY, n, solved);

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

    cout << "All Rabbit paths (0,0 → 2,2):\n\n";
    RabbitMaze(arr, 0, 0, 2, 2, 5, solved);
    cout << "Total Rabbit paths: " << solR << "\n\n";

    cout << "All Cat paths (4,4 → 2,2):\n\n";
    CatMaze(arr, 4, 4, 2, 2, 5, solved);
    cout << "Total Cat paths: " << solC << "\n\n";

    cout << "Intersection points (cells visited by both Rabbit and Cat): ";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (RVisited[i][j] == 1 && CVisited[i][j] == 1)
                cout << "(" << i << "," << j << ") ";
        }
    }
    cout << endl;

    return 0;
}
