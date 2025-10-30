#include <iostream>
using namespace std;

int main() {
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Insertion
    int posInsert = 3, element = 99;
    for (int i = n; i >= posInsert; i--)
        arr[i] = arr[i - 1];
    arr[posInsert - 1] = element;
    n++;

    cout << "After Insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Deletion
    int posDelete = 2;
    for (int i = posDelete - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;

    cout << "After Deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
