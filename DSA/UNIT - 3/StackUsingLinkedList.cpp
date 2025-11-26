#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if(top == NULL) {
            cout << "Stack Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
}
