#include <iostream>
using namespace std;

int main() {
    int a = 20;
    int *validPtr = &a;  // valid pointer
    int *nullPtr = nullptr;  // null pointer
    int *wildPtr;  // wild pointer (uninitialized)

    cout << "Valid Pointer points to value: " << *validPtr << endl;
    cout << "Null Pointer: " << nullPtr << endl;
    // cout << *wildPtr;  // Undefined behavior

    return 0;
}
