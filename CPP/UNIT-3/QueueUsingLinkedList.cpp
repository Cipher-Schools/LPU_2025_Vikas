#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
            cout << x << " enqueued\n";
            return;
        }

        rear->next = newNode;
        rear = newNode;
        cout << x << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " dequeued\n";

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
