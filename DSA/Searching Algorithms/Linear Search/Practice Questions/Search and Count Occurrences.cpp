#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 2, 6, 7, 2, 9, 4};
    int n = 8;
    int key = 2;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            count++;
    }

    if (count == 0)
        cout << "Element not found!";
    else
        cout << "Element " << key << " occurs " << count << " times.";

    return 0;
}
