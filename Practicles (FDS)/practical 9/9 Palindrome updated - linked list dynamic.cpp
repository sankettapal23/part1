#include<iostream>
#include<string>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    char data;       // Data of the node
    Node* next;      // Pointer to the next node
    Node(char val) : data(val), next(nullptr) {}  // Constructor to initialize the node with data
};

// Stack class using a linked list
class Stack {
private:
    Node* top;   // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = nullptr;
    }

    // Function to push a character onto the stack
    void push(char x) {
        Node* newNode = new Node(x);   // Create a new node with the given character
        newNode->next = top;           // Set the next pointer of the new node to the current top
        top = newNode;                 // Update the top to the new node
    }

    // Function to pop a character from the stack
    char pop() {
        if (top == nullptr) {
            cout << "Stack underflow ";  // Check if the stack is empty
            return -1;
        }

        char data = top->data;   // Retrieve the data from the top node
        Node* temp = top;        // Create a temporary pointer to the top node
        top = top->next;         // Update the top to the next node
        delete temp;             // Delete the temporary node

        return data;             // Return the popped character
    }

    // Function to display the elements of the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is Empty: ";
        }

        cout << "Stack is: ";
        Node* current = top;     // Start from the top of the stack
        while (current != nullptr) {
            cout << current->data << " ";  // Print the data of each node
            current = current->next;        // Move to the next node
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;                // Create an instance of the Stack class
    string input;
    char character;
    int flag = 1, i = 0;

    cout << "Enter a String: ";
    getline(cin, input);
    string org_str = "";

    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        if (ch >= 'a' and ch <= 'z') {
            ch = (char)(ch - 'a' + 'A');  // Convert lowercase letters to uppercase
        }
        if (ch >= 'A' and ch <= 'Z') {
            s.push(ch);                   // Push uppercase letters onto the stack
            org_str.push_back(ch);        // Build the original string with uppercase letters
        }
    }
    cout << endl;
    s.display();                         // Display the contents of the stack

    while (org_str[i] != '\0') {
        character = s.pop();             // Pop characters from the stack
        if (character != org_str[i])
            flag = 0;                    // Check if the characters match the original string
        i++;
    }
    cout << "Given String is " << (flag ? "" : "Not ") << "a Palindrome." << endl;  // Check if the string is a palindrome

    return 0;
}