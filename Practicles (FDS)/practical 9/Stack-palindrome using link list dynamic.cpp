#include <iostream>
#include <string>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    char data;     // Data of the node (a character)
    Node* next;    // Pointer to the next node in the linked list
};

// Define a class for a linked list
class LinkedList {
public:
    // Constructor initializes the head of the linked list to nullptr
    LinkedList() : head(nullptr) {}

    // Function to push a new node with data onto the front of the linked list
    void push(char data) {
        Node* newNode = new Node{data, nullptr}; // Create a new node
        if (!head) {
            head = newNode; // If the list is empty, set the new node as the head
        } else {
            newNode->next = head; // If not empty, link the new node to the current head
            head = newNode;       // Update the head to the new node
        }
    }

    // Function to pop the front node from the linked list and return its data
    char pop() {
        if (!head) {
            cerr << "Error: Trying to pop from an empty list.\n"; // Error message for empty list
            return '\0'; // Return a placeholder for an empty list
        }

        char data = head->data; // Retrieve data from the front node
        Node* temp = head;      // Save the pointer to the front node
        head = head->next;      // Move the head to the next node
        delete temp;            // Delete the front node to free memory
        return data;            // Return the data of the popped node
    }

    // Destructor to free memory by deleting all nodes in the linked list
    ~LinkedList() {
        while (head) {
            Node* temp = head; // Save the pointer to the current head
            head = head->next; // Move the head to the next node
            delete temp;       // Delete the current node to free memory
        }
    }

private:
    Node* head; // Pointer to the head of the linked list
};

// Function to check if a given string is a palindrome using a linked list
bool isPalindrome(const string& str) {
    LinkedList charList; // Create a linked list to store characters

    // Push characters onto the linked list
    for (char ch : str)
        charList.push(ch);

    // Pop characters and compare with the original string
    for (char ch : str) {
        if (ch != charList.pop())
            return false; // If characters don't match, the string is not a palindrome
    }

    return true; // If all characters match, the string is a palindrome
}

// Main function
int main() {
    string input;
    cout << "Enter the string to check if it is a palindrome: ";
    getline(cin, input);

    if (isPalindrome(input))
        cout << "STRING IS A PALINDROME\n";
    else
        cout << "STRING IS NOT A PALINDROME\n";

    return 0;
}
