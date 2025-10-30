#include <iostream>
using namespace std;

void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    swapValue(x, y);
    cout << "Call by Value: " << x << " " << y << endl;  // No change

    swapReference(x, y);
    cout << "Call by Reference: " << x << " " << y << endl; // Swapped
    return 0;
}
