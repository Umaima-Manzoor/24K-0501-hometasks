// Shell sort performs fewwer comparisons as compared to bubble sort due to the reduced gaps. Since it's suitable for larger datasets and its time completixity if O(n log n) in the average and worst cases, it is more efficient than bubble sort which has a time complexity of O(n^2). This is why the airport prefers shell sort as it is faster and minimizes waiting time for passengers.

// If the luggage is nearly sorted, shell sort can perform significantly better than O(n log n) time complexity, approaching O(n) in the best case. This is because the algorithm can quickly identify and place elements in their correct positions with fewer comparisons and movements.

#include <iostream>
using namespace std;


void ShellSort(int arr[], int n) {
    for (int gap=n/2; gap>0; gap/=2) {

        for (int j=gap; j<n; j++) {
            int temp = arr[j];
            int res = j;


            while (res>= gap && arr[res-gap > temp]) {
                arr[res] = arr[res-gap];
                res -= gap;
            }

            arr[res] = temp;
        }

        cout << "After gap = " << gap << ": ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
}

int main() {
    int weights[] = {32, 25, 40, 12, 18, 50, 28};

    ShellSort(weights, 7);


    cout << "Sorted array: ";
    for (int i = 0; i < 7; i++) {
        cout << weights[i] << " ";
    }

    return 0;
}
