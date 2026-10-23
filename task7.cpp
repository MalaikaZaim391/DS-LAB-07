#include <iostream>

using namespace std;

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int getMax(const int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

void countSortDigit(int arr[], int n, int exp) {
    int output[100]; //Assuming n < 100 for static size safety
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int pass = 1;

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSortDigit(arr, n, exp);
        cout << "After Pass " << pass++ << " (Digit pos " << exp << "): ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {91, 8, 1024, 56, 305, 7, 120};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Patient Record IDs: ";
    printArray(arr, n);
    cout << "-------------------------------------------\n";

    radixSort(arr, n);

    return 0;
}
