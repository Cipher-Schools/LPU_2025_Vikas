#include <iostream>
using namespace std;

int x = 10; // Global

int main() {
    int x = 5; // Local
    cout << "Local x: " << x << endl;
    cout << "Global x: " << ::x << endl; // Scope resolution
    return 0;
}
