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

void countingSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int* count = new int[maxVal + 1]();
    int* output = new int[n];

    //Frequency count
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    cout << "--- FREQUENCY COUNT FOR PRESENT ELEMENTS ---\n";
    for (int i = 0; i <= maxVal; i++) {
        if (count[i] > 0) {
            cout << "Value " << i << ": " << count[i] << " time(s)\n";
        }
    }

    //Cumulative count
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    cout << "\n--- CUMULATIVE COUNT (NON-ZERO DELTAS) ---\n";
    for (int i = 0; i <= maxVal; i++) {
        if (i == 0 && count[i] > 0) {
            cout << "Val " << i << " -> Cum: " << count[i] << "\n";
        } else if (i > 0 && count[i] != count[i - 1]) {
            cout << "Val " << i << " -> Cum: " << count[i] << "\n";
        }
    }

    //Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    cout << "\nOutput Array (Sorted): ";
    printArray(output, n);

    //Copy back
    for (int i = 0; i < n; i++) arr[i] = output[i];

    delete[] count;
    delete[] output;
}

int main() {
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Order IDs: ";
    printArray(arr, n);
    cout << "\n";

    countingSort(arr, n);

    return 0;
}
