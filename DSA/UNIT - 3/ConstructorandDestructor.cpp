#include <iostream>
using namespace std;

class Demo {
public:

    // Constructor
    Demo() {
        cout << "Constructor called: Object Created" << endl;
    }

    // Destructor
    ~Demo() {
        cout << "Destructor called: Object Destroyed" << endl;
    }
};

int main() {
    Demo obj;  // Object created → Constructor automatically runs

    cout << "Inside main function..." << endl;

    // When main() ends, obj goes out of scope → Destructor runs
    return 0;
}
