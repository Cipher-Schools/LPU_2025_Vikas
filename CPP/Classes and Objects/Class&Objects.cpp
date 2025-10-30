//Class: User-defined data type containing data members (variables) and member functions (methods).
// Object: Instance of a class.

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Vikas";
    s1.age = 21;
    s1.display();
    return 0;
}
