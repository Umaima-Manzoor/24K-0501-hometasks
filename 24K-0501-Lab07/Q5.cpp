#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int compCount = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int start, int end, int pivotIndex) {
    swap(arr[pivotIndex], arr[end]);
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            compCount++;
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(int arr[], int start, int end, string method) {
    if (start < end) {
        int pivotIndex = end;

        if (method == "first") {
            pivotIndex = start;
        } else if (method == "random") {
            pivotIndex = start + rand() % (end - start + 1);
        } else if (method == "middle") {
            pivotIndex = start + (end - start) / 2;
        } else if (method == "median3") {
            int mid = start + (end - start) / 2;
            int a = arr[start], b = arr[mid], c = arr[end];
            if ((a > b) != (a > c)) {
                pivotIndex = start;
            } else if ((b > a) != (b > c)) {
                pivotIndex = mid;
            } else {
                pivotIndex = end;
            }
        }

        int p = partition(arr, start, end, pivotIndex);
        quickSort(arr, start, p - 1, method);
        quickSort(arr, p + 1, end, method);
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    int arr[n], temp[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    copyArray(arr, temp, n);
    compCount = 0;
    quickSort(temp, 0, n - 1, "first");
    cout << "\nPivot: First element" << endl;
    cout << "Sorted array: "; printArray(temp, n);
    cout << "Number of comparisons: " << compCount << endl;

    copyArray(arr, temp, n);
    compCount = 0;
    quickSort(temp, 0, n - 1, "random");
    cout << "\nPivot: Random element" << endl;
    cout << "Sorted array: "; printArray(temp, n);
    cout << "Number of comparisons: " << compCount << endl;

    copyArray(arr, temp, n);
    compCount = 0;
    quickSort(temp, 0, n - 1, "middle");
    cout << "\nPivot: Middle element" << endl;
    cout << "Sorted array: "; printArray(temp, n);
    cout << "Number of comparisons: " << compCount << endl;

    copyArray(arr, temp, n);
    compCount = 0;
    quickSort(temp, 0, n - 1, "median3");
    cout << "\nPivot: Median of three" << endl;
    cout << "Sorted array: "; printArray(temp, n);
    cout << "Number of comparisons: " << compCount << endl;

    return 0;
}
