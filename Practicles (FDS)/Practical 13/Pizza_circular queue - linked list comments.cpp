#include<iostream>
using namespace std;

// Node class to represent each order in the linked list
class Node {
public:
    int data;      // Data of the order (order id)
    Node* next;    // Pointer to the next order in the linked list

    // Constructor to initialize the order with data
    Node(int val) : data(val), next(nullptr) {}
};

// PizzaParlour class using a linked list
class PizzaParlour {
private:
    Node* front;    // Pointer to the front of the linked list (head)
    Node* rear;     // Pointer to the rear of the linked list (tail)
    int id;         // Counter for generating order ids

public:
    // Constructor to initialize an empty PizzaParlour
    PizzaParlour() : front(nullptr), rear(nullptr), id(0) {}

    // Function to add an order to the PizzaParlour
    bool addOrder(int data);

    // Function to serve an order from the PizzaParlour
    void serveOrder();

    // Function to display the orders in the PizzaParlour
    void display();
};

// Function to add an order to the PizzaParlour
bool PizzaParlour::addOrder(int data) {
    Node* newNode = new Node(data);   // Create a new node for the order

    if (rear == nullptr) {
        front = rear = newNode;       // If the PizzaParlour is empty, set both front and rear to the new node
    } else {
        rear->next = newNode;         // Otherwise, add the new node to the end of the linked list
        rear = newNode;               // Update the rear pointer to the new node
    }

    cout << "Thank you for the order. Order id is: " << data << endl;
    return true;
}

// Function to serve an order from the PizzaParlour
void PizzaParlour::serveOrder() {
    if (front == nullptr) {
        cout << "\nNo Orders in Cafe. [Cafe is Empty]\n";
        return;
    }

    Node* temp = front;           // Create a temporary pointer to the front order
    cout << "\nOrder No. " << temp->data << " is processed.\n";
    front = front->next;          // Update the front pointer to the next order
    delete temp;                  // Delete the temporary node

    if (front == nullptr) {
        rear = nullptr;            // If there are no more orders, update the rear pointer to nullptr
    }
}

// Function to display the orders in the PizzaParlour
void PizzaParlour::display() {
    if (front == nullptr) {
        cout << "\nCafe is Empty. No orders.\n";
        return;
    }

    Node* temp = front;           // Start from the front of the linked list

    cout << "Order Id's: \n";
    while (temp != nullptr) {
        cout << temp->data << "  ";  // Print the data (order id) of each node
        temp = temp->next;            // Move to the next node
    }
    cout << endl;
}

// Function to display introductory message
void intro() {
    char name[50] = {"\n  Cafe \n"};
    for (int i = 0; name[i] != '\0'; i++) {
        cout << name[i];
    }
}

// Main function
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
                q.addOrder(++(q.id));   // Increment id and add a new order
                break;

            case 2:
                q.serveOrder();          // Serve an order
                break;

            case 3:
                q.display();             // Display orders
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