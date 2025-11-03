#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;  // pointer to first element

    cout << "Initial Address: " << p << ", Value: " << *p << endl;
    p++;
    cout << "After p++ Address: " << p << ", Value: " << *p << endl;
    p--;
    cout << "After p-- Address: " << p << ", Value: " << *p << endl;

    return 0;
}
