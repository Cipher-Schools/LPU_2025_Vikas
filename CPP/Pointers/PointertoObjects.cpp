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
    Student s1 = {"Vikas", 22};
    Student *ptr = &s1;

    ptr->display();
    ptr->age = 23;
    ptr->display();

    return 0;
}
