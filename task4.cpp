#include <iostream>
#include <utility>

using namespace std;

int partitionCount = 0;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}

int partition(int arr[], int low, int high, int totalSize) {
    int pivot = arr[high]; 
    cout << "Partition Call " << (partitionCount + 1) 
         << " | Subarray bounds: [" << low << ", " << high 
         << "] | Chosen Pivot: " << pivot << "\n";

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    partitionCount++;
    cout << "Array after Partition " << partitionCount << ": ";
    printArray(arr, totalSize);
    cout << "--------------------------------------------------\n";

    return i + 1;
}

void quickSort(int arr[], int low, int high, int totalSize) {
    if (low < high) {
        int pi = partition(arr, low, high, totalSize);
        quickSort(arr, low, pi - 1, totalSize);
        quickSort(arr, pi + 1, high, totalSize);
    }
}

int main() {
    int arr[] = {40, 20, 70, 10, 60, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Array: ";
    printArray(arr, n);
    cout << "--------------------------------------------------\n";

    quickSort(arr, 0, n - 1, n);

    cout << "Total Partition Operations: " << partitionCount << "\n";
    cout << "Final Sorted Array: ";
    printArray(arr, n);

    return 0;
}
