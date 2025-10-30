#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 3, 40, 15};
    int n = 5;
    int largest = arr[0], smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest;
    return 0;
}
