//Shell Sort is more efficient than Insertion Sort because it sorts elements at specific gaps, allowing distant elements to move closer to their correct positions early. This reduces the total number of comparisons and shifts, making the algorithm faster, especially for larger or unsorted datasets.

#include <iostream>
using namespace std;

void ShellSort(int arr[], int n) {
    for (int gap = n/2; gap>0; gap/=2) {

        for (int j=gap; j<n; j++) {
            int temp = arr[j];
            int res = j;

            while(res>=gap && arr[res-gap]>temp) {
                arr[res] = arr[res-gap];
                res = res - gap;
            }
            arr[res] = temp;
        }

        cout << "After gap = " << gap << ": ";
        for (int i=0; i<6; i++) {
        cout<<arr[i]<<" ";
        }
        cout << endl<< endl;
    }
}


int main () {

    int arr[] = {205, 102, 310, 450, 120, 90};

    ShellSort(arr, 6);

    cout << "Sorted array: ";
    for (int i=0; i<6; i++) {
        cout<<arr[i]<<" ";
    }


    return 0;
}
