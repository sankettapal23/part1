#include<iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    char data;               // Data of the node
    Node* next;              // Pointer to the next node
    Node(char val) : data(val), next(nullptr) {}  // Constructor to initialize the node with data
};

// Stack class using a linked list
class stack {
private:
    Node* top;            // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    stack() {
        top = nullptr;
    }

    // Function to push a character onto the stack
    void push(char b) {
        Node* newNode = new Node(b);   // Create a new node with the given character
        newNode->next = top;           
// Set the next pointer of the new node to the current top
        top = newNode;                 
// Update the top to the new node
    }

    // Function to pop a character from the stack
    void pop(char x) {
        if (top == nullptr) {
            cout << "Expression is not well paranthesis" << endl;
            exit(0);                   
// Exit the program if pop is attempted on an empty stack
        }

        // Check if the closing parenthesis matches the corresponding opening parenthesis
        if ((x == ')' && top->data == '(') || (x == ']' && top->data == '[') || (x == '}' && top->data == '{')) {
            Node* temp = top;        // Create a temporary pointer to the top node
            top = top->next;         
// Update the top to the next node
            delete temp;             
// Delete the temporary node
        } else {
            cout << "Expression is not well paranthesis" << endl;
            exit(0);                   
// Exit the program if there is a mismatch in parentheses
        }
    }

    // Function to check if the stack is empty
    int check() {
        return (top == nullptr);
    }
};

int main() {
    char eq[30];
    int i;
    stack s;
    cout << "\nEnter the expression: ";
    cin >> eq;

    for (i = 0; eq[i] != '\0'; i++) {
        if (eq[i] == '(' || eq[i] == '[' || eq[i] == '{') {
            s.push(eq[i]);         
// Push opening parentheses onto the stack
        } else if (eq[i] == ')' || eq[i] == ']' || eq[i] == '}') {
            s.pop(eq[i]);    //Pop and check closing parentheses
        }
    }

    int c = s.check();
    if (c == 1) {
        cout << "\nExpression is well paranthesis" << endl;
    } else {
        cout << "\nExpression is not well paranthesis" << endl;
    }

    return 0;
}
