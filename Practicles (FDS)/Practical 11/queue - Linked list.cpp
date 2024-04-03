#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void insert();
    void delete1();
    void display();
    int isfull();
    int isempty();
};

void Queue::insert() {
    int no;
    cout << "Enter number: ";
    cin >> no;

    Node* newNode = new Node(no);
    
    if (isempty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Element " << no << " inserted into the queue.\n";
}

void Queue::delete1() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        Node* temp = front;
        int no = temp->data;
        front = front->next;
        delete temp;

        cout << "Element " << no << " deleted from the queue.\n";
    }
}

void Queue::display() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        Node* temp = front;

        cout << "Queue is: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int Queue::isfull() {
    return 0; // Linked list implementation, so not applicable
}

int Queue::isempty() {
    return (front == nullptr);
}

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