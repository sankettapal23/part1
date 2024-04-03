#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node() {
       // data = value;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;
    const int maxSize;

    Queue(int size = 5) {
    front = nullptr;
    rear = nullptr;
    maxSize = size;
}
    void enqueue();
    void dequeue();
    void display();
    bool isEmpty();
    bool isFull();
};

void Queue::enqueue() {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue.\n";
    } else {
        int value;
        cout << "Enter number: ";
        cin >> value;

        Node* newNode = new Node;  // Allocate memory for a new node

        newNode->data = value;  // Set the data after allocation

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Element " << value << " enqueued to the queue.\n";
    }
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
    } else {
        Node* temp = front;
        int value = temp->data;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }

        delete temp;
        cout << "Element " << value << " dequeued from the queue.\n";
    }
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue elements: ";
        for (Node* current = front; current != nullptr; current = current->next) {
            cout << current->data << " ";
        }
        cout << endl;
    }
}

bool Queue::isEmpty() {
    return front == nullptr;
}

bool Queue::isFull() {
    int count = 0;
    for (Node* current = front; current != nullptr; current = current->next) {
        count++;
    }
    return count >= maxSize;
}

int main() {
    int ch;
    Queue q(5);

    do {
        cout << "Enter choice\n";
        cout << "1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Wrong choice\n";
                break;
        }
    } while (ch != 4);

    return 0;
}
