#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    cout << "After sorting with exp " << exp << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    cout << endl;

    delete[] output;
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    const int n = 20;
    int arr[n];

    cout << "Enter 20 product IDs (5-digit integers):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before Sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    
    cout << endl;

    radixSort(arr, n);

    cout << "After Sorting (Ascending):" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    cout << endl;

    return 0;
}
