#include <iostream>
using namespace std;

class Student {
public:
    // Default Constructor
    Student() {
        cout << "Default Constructor Called!" << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor Called!" << endl;
    }
};

int main() {
    Student s1;  // Object created → Default constructor runs

    cout << "Inside main function..." << endl;

    // When main ends, s1 is destroyed → Destructor runs
    return 0;
}
