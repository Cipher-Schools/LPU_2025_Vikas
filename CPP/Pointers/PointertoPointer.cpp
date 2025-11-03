#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *p = &x;     // pointer to int
    int **pp = &p;   // pointer to pointer

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p (address of x): " << p << endl;
    cout << "Value stored in *p: " << *p << endl;
    cout << "Value of pp (address of p): " << pp << endl;
    cout << "Value stored in *pp: " << *pp << endl;
    cout << "Value stored in **pp: " << **pp << endl;

    return 0;
}
