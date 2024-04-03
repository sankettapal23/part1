#include<iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;               // Data of the node
    Node* next;             // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {}  // Constructor to initialize the node with data
};

// Queue class using a linked list
class Queue {
private:
    Node* front;            // Pointer to the front of the queue
    Node* rear;             // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = rear = nullptr;
    }

    // Function to insert a number into the queue
    void insert() {
        int no;
        cout << "Enter number: ";
        cin >> no;

        Node* newNode = new Node(no);

        if (isempty()) {
            front = rear = newNode;   // If the queue is empty, set both front and rear to the new node
        } else {
            rear->next = newNode;      // Otherwise, add the new node to the end of the queue
            rear = newNode;            // Update the rear pointer to the new node
        }

        cout << "Element " << no << " inserted into the queue.\n";
    }

    // Function to delete a number from the queue
    void delete1() {
        if (isempty()) {
            cout << "Queue is empty\n";
        } else {
            Node* temp = front;        // Create a temporary pointer to the front node
            int no = temp->data;       // Retrieve the data from the front node
            front = front->next;       // Update the front pointer to the next node
            delete temp;               // Delete the temporary node

            cout << "Element " << no << " deleted from the queue.\n";
        }
    }

    // Function to display the elements of the queue
    void display() {
        if (isempty()) {
            cout << "Queue is empty\n";
        } else {
            Node* temp = front;        // Start from the front of the queue

            cout << "Queue is: ";
            while (temp != nullptr) {
                cout << temp->data << " ";  // Print the data of each node
                temp = temp->next;           // Move to the next node
            }
            cout << endl;
        }
    }

    // Function to check if the queue is full (not applicable for linked list implementation)
    int isfull() {
        return 0;
    }

    // Function to check if the queue is empty
    int isempty() {
        return (front == nullptr);
    }
};

// Main function
int main() {
    int ch;
    Queue q;

    while (ch != 4) {
        cout << "Enter choice\n";
        cout << "1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                q.insert();
                break;
            case 2:
                q.delete1();
                break;
            case 3:
                q.display();
                break;
            case 4:
                break;
            default:
                cout << "Wrong choice\n";
                break;
        }
    }

    return 0;
}