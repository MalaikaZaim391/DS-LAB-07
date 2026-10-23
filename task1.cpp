#include <iostream>

using namespace std;

int mergeCount = 0;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void merge(int arr[], int left, int mid, int right, int totalSize) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    mergeCount++;
    cout << "After Merge Operation " << mergeCount << ": ";
    printArray(arr, totalSize);
}

void mergeSort(int arr[], int left, int right, int totalSize) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, totalSize);
        mergeSort(arr, mid + 1, right, totalSize);
        merge(arr, left, mid, right, totalSize);
    }
}

int main() {
    int arr[] = {78, 45, 92, 63, 45, 88, 51, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Array: ";
    printArray(arr, n);
    cout << "-------------------------------------\n";

    mergeSort(arr, 0, n - 1, n);

    cout << "-------------------------------------\n";
    cout << "Total Merge Operations: " << mergeCount << "\n";
    cout << "Final Sorted Array: ";
    printArray(arr, n);

    return 0;
}
