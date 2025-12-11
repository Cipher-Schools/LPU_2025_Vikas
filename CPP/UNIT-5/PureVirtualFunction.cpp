#include <iostream>
using namespace std;

class Animal {
public: 
    virtual void sound() = 0;  //virtual function
        // cout << "Animal makes a sound\n";
};

class Dog : public Animal {
public: 
    void sound() override { //override keyword(optional)
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public: 
    void sound() override {
        cout << "Cat Meows\n";
    }
};

int main() {
    
    Animal *a; //Base class pointer
    
    Dog d;
    Cat c;
    
    a = &d;
    a->sound(); //Dog barks(runtime binding)
    
    a = &c;
    a->sound(); //Cat Meows(runtime binding)
    
    return 0;
}
