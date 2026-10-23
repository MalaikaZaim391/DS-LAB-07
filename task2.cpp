#include <iostream>

using namespace std;

int comparisonCount = 0;

void printSubArray(const int arr[], int start, int end) {
    cout << "[ ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << (i == end ? "" : ", ");
    }
    cout << " ]";
}

void merge(int arr[], int left, int mid, int right) {
    cout << "Left Subarray: ";
    printSubArray(arr, left, mid);
    cout << " | Right Subarray: ";
    printSubArray(arr, mid + 1, right);
    cout << "\n";

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisonCount++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "--- MERGE PROCESS ---\n";
    mergeSort(arr, 0, n - 1);

    cout << "\n-------------------------------------\n";
    cout << "Final Sorted Prices: ";
    printSubArray(arr, 0, n - 1);
    cout << "\nTotal Comparisons: " << comparisonCount << "\n";

    return 0;
}
