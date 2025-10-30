#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
};

int main() {
    Student s1 = {1, "John"};
    cout << s1.id << " " << s1.name << endl;
    return 0;
}
