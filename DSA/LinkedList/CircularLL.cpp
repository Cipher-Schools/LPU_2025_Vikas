#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Circular Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at given position (1-based)
    void insertAtPosition(int pos, int val) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node(val);

        // Case 1: Insert at beginning
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count != pos - 1) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Last node deleted.\n";
            return;
        }

        Node* temp = head;
        Node* tail = head;

        while (tail->next != head)
            tail = tail->next;

        head = head->next;
        tail->next = head;
        delete temp;

        cout << "Node deleted from beginning.\n";
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Last node deleted.\n";
            return;
        }

        Node* temp = head;
        while (temp->next->next != head)
            temp = temp->next;

        delete temp->next;
        temp->next = head;

        cout << "Node deleted from end.\n";
    }

    // Delete at given position
    void deleteAtPosition(int pos) {
        if (head == nullptr || pos <= 0) {
            cout << "Invalid operation!\n";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head) {
            cout << "Position out of range!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "Node deleted at position " << pos << ".\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.insertAtPosition(3, 15);
    list.display();

    list.deleteAtBeginning();
    list.display();

    list.deleteAtEnd();
    list.display();

    list.deleteAtPosition(2);
    list.display();

    return 0;
}
