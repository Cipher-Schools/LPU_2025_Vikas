#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
};

int main() {
    Data d;
    d.i = 10;
    cout << d.i << endl;
    d.f = 20.5;
    cout << d.f << endl; // i is now lost
    return 0;
}
