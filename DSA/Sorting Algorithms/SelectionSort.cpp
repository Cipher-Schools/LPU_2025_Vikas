#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // assume current as minimum

        // find the minimum in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // swap minimum element with first element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}