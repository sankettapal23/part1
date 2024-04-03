#include<iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

class stack {
private:
    Node* top;

public:
    stack() {
        top = nullptr;
    }

    void push(char b) {
        Node* newNode = new Node(b);
        newNode->next = top;
        top = newNode;
    }

    void pop(char x) {
        if (top == nullptr) {
            cout << "Expression is not well paranthesis" << endl;
            exit(0);
        }

        if ((x == ')' && top->data == '(') || (x == ']' && top->data == '[') || (x == '}' && top->data == '{')) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "Expression is not well paranthesis" << endl;
            exit(0);
        }
    }

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
        } else if (eq[i] == ')' || eq[i] == ']' || eq[i] == '}') {
            s.pop(eq[i]);
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