#include <iostream>
using namespace std;

//Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
//Partition Function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; //We choose last element as pivot
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]); //Place pivot in correct position
    return i + 1;
}
//Quick sort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);  //Sort left side & elements here are less than pivot
        quickSort(arr, pi+ 1, high); //Sort right side & elements here are greater than pivot
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    quickSort(arr, 0, size - 1);
    cout << "\nSorted Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
    