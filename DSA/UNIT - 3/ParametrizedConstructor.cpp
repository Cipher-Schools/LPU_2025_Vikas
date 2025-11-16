#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Default Constructor
    Student() {
        cout << "Default Constructor Called!" << endl;
        name = "Unknown";
        age = 0;
    }

    // Parameterized Constructor
    Student(string n, int a) {
        cout << "Parameterized Constructor Called!" << endl;
        name = n;
        age = a;
    }

    // Display Function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor Called for " << name << endl;
    }
};

int main() {

    // Object using Default Constructor
    Student s1;
    s1.display();

    // Object using Parameterized Constructor
    Student s2("Vikas", 23);
    s2.display();

    return 0;
}
