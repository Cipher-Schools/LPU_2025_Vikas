#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    // Input size of first array
    cout << "Enter size of first array: ";
    cin >> n1;
    int arr1[n1];

    cout << "Enter elements of first array:\n";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input size of second array
    cout << "Enter size of second array: ";
    cin >> n2;
    int arr2[n2];

    cout << "Enter elements of second array:\n";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Merging arrays
    int merged[n1 + n2];
    for (int i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }

    // Display merged array
    cout << "Merged Array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << merged[i] << " ";
    }

    return 0;
}