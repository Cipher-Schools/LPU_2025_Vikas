#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {2, 4, 4, 4, 6, 8, 10};
    int n = 7, key = 4;

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    if (first == -1)
        cout << "Element not found!";
    else {
        int count = last - first + 1;
        cout << "Element " << key << " occurs " << count << " times.";
    }

    return 0;
}
