#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 30, 25, 40, 25, 50};
    int n = 7;
    int key = 25;
    bool found = false;

    cout << "Element " << key << " found at indices: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "Not found!";

    return 0;
}
