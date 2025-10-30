#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int n = 5;
    int key = 45;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found!";

    return 0;
}
