#include <iostream>
using namespace std;

int add(int a, int b = 5) {
    return a + b;
}

int main() {
    cout << add(10) << endl; // Uses default b = 5
    cout << add(10, 20);
    return 0;
}
