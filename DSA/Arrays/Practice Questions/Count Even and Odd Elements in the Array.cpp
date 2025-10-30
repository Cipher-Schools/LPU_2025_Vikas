#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 8, 12, 3, 7, 6, 10};
    int n = 7;
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "Even elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount;

    return 0;
}
