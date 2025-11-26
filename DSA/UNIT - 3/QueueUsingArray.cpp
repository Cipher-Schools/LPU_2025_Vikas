#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if(rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }
        if(front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int Front() {
        if(front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.Front() << endl;
    q.dequeue();
    cout << q.Front() << endl;
}
