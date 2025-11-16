#include <iostream>
using namespace std;

class Queue {
public:
    int arr[10];   // fixed-size array
    int front, rear, capacity;

    Queue(int size = 10) {
        front = -1;
        rear = -1;
        capacity = size;
    }

    // Enqueue operation
    void enqueue(int x) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) 
            front = 0;

        arr[++rear] = x;
        cout << x << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " dequeued\n";
        front++;
    }

    // Peek operation
    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
