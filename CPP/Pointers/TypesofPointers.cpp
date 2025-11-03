#include <iostream>
using namespace std;

int main() {
    int a = 100;
    int *nullPtr = nullptr;
    void *voidPtr = &a;
    int *const constPtr = &a;
    const int *ptrToConst = &a;

    cout << "Void pointer points to value: " << *((int*)voidPtr) << endl;
    cout << "Constant pointer value: " << *constPtr << endl;
    cout << "Pointer to constant value: " << *ptrToConst << endl;

    return 0;
}
