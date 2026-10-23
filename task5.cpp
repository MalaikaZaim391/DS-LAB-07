#include <iostream>
#include <utility>

using namespace std;

int partitionCount = 0;
int comparisonCount = 0;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}

int partitionFirstPivot(int arr[], int low, int high, int totalSize) {
    int pivot = arr[low]; 
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high) {
            comparisonCount++;
            if (arr[i] > pivot) break;
            i++;
        }
        while (j >= low + 1) {
            comparisonCount++;
            if (arr[j] <= pivot) break;
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[j]);

    partitionCount++;
    cout << "Partition " << partitionCount << " | Pivot: " << pivot << " | Array state: ";
    printArray(arr, totalSize);

    return j;
}

void quickSort(int arr[], int low, int high, int totalSize) {
    if (low < high) {
        int pi = partitionFirstPivot(arr, low, high, totalSize);
        quickSort(arr, low, pi - 1, totalSize);
        quickSort(arr, pi + 1, high, totalSize);
    }
}

int main() {
    int arr[] = {55, 25, 75, 15, 65, 35, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);
    cout << "------------------------------------\n";

    quickSort(arr, 0, n - 1, n);

    cout << "------------------------------------\n";
    cout << "Total Comparisons: " << comparisonCount << "\n";
    cout << "Final Sorted Array: ";
    printArray(arr, n);

    return 0;
}
