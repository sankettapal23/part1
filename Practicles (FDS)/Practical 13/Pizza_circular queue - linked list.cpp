#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class PizzaParlour {
private:
    Node* front;
    Node* rear;
    int id;

public:
    PizzaParlour() : front(nullptr), rear(nullptr), id(0) {}

    bool addOrder(int data);
    void serveOrder();
    void display();
};

bool PizzaParlour::addOrder(int data) {
    Node* newNode = new Node(data);

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Thank you for the order. Order id is: " << data << endl;
    return true;
}

void PizzaParlour::serveOrder() {
    if (front == nullptr) {
        cout << "\nNo Orders in Cafe. [Cafe is Empty]\n";
        return;
    }

    Node* temp = front;
    cout << "\nOrder No. " << temp->data << " is processed.\n";
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }
}

void PizzaParlour::display() {
    if (front == nullptr) {
        cout << "\nCafe is Empty. No orders.\n";
        return;
    }

    Node* temp = front;
    cout << "Order Id's: \n";
    while (temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

void intro() {
    char name[50] = {"\n  Cafe \n"};
    for (int i = 0; name[i] != '\0'; i++) {
        cout << name[i];
    }
}

int main() {
    int ch;
    PizzaParlour q;

    do {
        cout << "\n-----------------";
        intro();
        cout << "-----------------";
        cout << "\n****Menu*****\n";
        cout << "1. Accept order\n";
        cout << "2. Serve order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";

        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                q.addOrder(++(q.id));
                break;

            case 2:
                q.serveOrder();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\nThank You. Keep Visiting.\n";
                break;

            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (ch != 4);

    return 0;
}