#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// LinkedList class containing all operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert node at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    //  Insert node at a given position (1-based index)
    void insertAtPosition(int pos, int val) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node(val);

        // Case 1: Insert at beginning
        if (pos == 1) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete node at beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
        cout << "Node deleted from beginning.\n";
    }

    // Delete node at end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (head->next == nullptr) { // Only one node
            delete head;
            head = nullptr;
            cout << "Last node deleted.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;

        cout << "Node deleted from end.\n";
    }

    // Delete node at a given position
    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        // Case 1: Delete at beginning
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            return;
        }

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Node deleted from position " << pos << ".\n";
    }

    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    LinkedList list;  // Object creation

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display();

    cout << "Inserting 5 at beginning...\n";
    list.insertAtBeginning(5);
    list.display();

    cout << "Inserting 25 at position 4...\n";
    list.insertAtPosition(4, 25);
    list.display();

    cout << "Deleting node at beginning...\n";
    list.deleteAtBeginning();
    list.display();

    cout << "Deleting node at end...\n";
    list.deleteAtEnd();
    list.display();

    cout << "Deleting node at position 3...\n";
    list.deleteAtPosition(3);
    list.display();

    return 0;
}
