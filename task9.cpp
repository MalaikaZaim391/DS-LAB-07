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

void countingSortSubroutine(int arr[], int n, int exp, int passNum) {
    int* output = new int[n];
    int count[10] = {0};

    cout << "\n=================== PASS " << passNum << " (exp = " << exp << ") ===================\n";

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    cout << "Frequency Count Array [0-9]: ";
    printArray(count, 10);

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    cout << "Cumulative Count Array [0-9]: ";
    printArray(count, 10);

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    cout << "Output Array after digit placement: ";
    printArray(output, n);

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    cout << "Original Array after copy-back:     ";
    printArray(arr, n);

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int passNum = 1;

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortSubroutine(arr, n, exp, passNum++);
    }
}

int main() {
    int trackingIDs[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
    int n = sizeof(trackingIDs) / sizeof(trackingIDs[0]);

    cout << "Original Tracking IDs: ";
    printArray(trackingIDs, n);

    radixSort(trackingIDs, n);

    return 0;
}
