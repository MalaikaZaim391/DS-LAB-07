#include <iostream>

using namespace std;

int recursiveCallCount = 0;
int mergeCount = 0;
int comparisonCount = 0;

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

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

    mergeCount++;

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int* arr, int left, int right) {
    recursiveCallCount++;
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of elements (n): ";
    cin >> n;

    if (n <= 0) {
        cerr << "Error: Invalid array size. 'n' must be greater than 0.\n";
        return 1;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "\n--- STATS & RESULTS ---\n";
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nRecursive Calls: " << recursiveCallCount;
    cout << "\nMerge Operations: " << mergeCount;
    cout << "\nElement Comparisons: " << comparisonCount << "\n";

    delete[] arr; 
    return 0;
}
