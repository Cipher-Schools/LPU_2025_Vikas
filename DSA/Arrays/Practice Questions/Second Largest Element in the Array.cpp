#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = 6;

    int largest = arr[0];
    int secondLargest = -1; // or INT_MIN for negatives

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == -1)
        cout << "No second largest element.";
    else
        cout << "Second largest element: " << secondLargest;

    return 0;
}
