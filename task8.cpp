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

void countingSortForRadix(int arr[], int n, int exp) {
    int* output = new int[n];
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

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int totalPasses = 0;

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        totalPasses++;
        countingSortForRadix(arr, n, exp);
        cout << "Array after Pass " << totalPasses << " (exp=" << exp << "): ";
        printArray(arr, n);
    }

    cout << "\nTotal passes required: " << totalPasses << "\n";
}

int main() {
    int arr[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Parcel Tracking IDs: ";
    printArray(arr, n);
    cout << "----------------------------------------------\n";

    radixSort(arr, n);

    return 0;
}
