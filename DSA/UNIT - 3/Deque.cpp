#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front, rear, size;

public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) ||
                (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = x;
        cout << x << " inserted at front\n";
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;
        cout << x << " inserted at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << arr[front] << " deleted from front\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << arr[rear] << " deleted from rear\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {

    Deque dq(5);   // creating object of deque

    dq.insertRear(10);    // calling functions
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteFront();
    dq.deleteRear();

    cout << "Front now: " << dq.getFront() << endl;
    cout << "Rear now: " << dq.getRear() << endl;

    return 0;
}
