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

void countingSortStable(int arr[], int n, int exp) {
    int output[100];
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
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    
    int maxPasses = 0;
    for (int temp = maxVal; temp > 0; temp /= 10) {
        maxPasses++;
    }

    cout << "Maximum digit passes required: " << maxPasses << "\n\n";

    int pass = 1;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortStable(arr, n, exp);
        cout << "Array after Pass " << pass++ << ": ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {7314, 314, 731, 34, 3147, 147, 47, 7314, 4, 314};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Accession Numbers: ";
    printArray(arr, n);
    cout << "---------------------------------------------------------\n";

    radixSort(arr, n);

    return 0;
}
