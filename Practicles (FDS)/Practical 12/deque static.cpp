#include<iostream>
using namespace std;

const int MAX_SIZE = 10; // Adjust the size as needed

struct node
{
    int data;
    node *next;
};

class dQ
{
    struct node elements[MAX_SIZE];
    int front, rear;

public:
    dQ()
    {
        front = rear = -1;
    }

    void enfront();
    void enrear();
    void defront();
    void derear();
    void display();
};

void dQ::enfront()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        cout << "Overflow\n";
        return;
    }

    int data;
    cout << "Enter the element - ";
    cin >> data;

    if (front == -1) // If the queue is empty
        front = rear = 0;
    else if (front == 0) // If front is at the beginning, wrap around
        front = MAX_SIZE - 1;
    else
        front--;

    elements[front].data = data;
}

void dQ::enrear()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        cout << "Overflow\n";
        return;
    }

    int data;
    cout << "Enter the element - ";
    cin >> data;

    if (front == -1) // If the queue is empty
        front = rear = 0;
    else if (rear == MAX_SIZE - 1) // If rear is at the end, wrap around
        rear = 0;
    else
        rear++;

    elements[rear].data = data;
}

void dQ::defront()
{
    if (front == -1)
    {
        cout << "Underflow\n";
        return;
    }

    if (front == rear)
        front = rear = -1;
    else if (front == MAX_SIZE - 1)
        front = 0;
    else
        front++;
}

void dQ::derear()
{
    if (front == -1)
    {
        cout << "Underflow\n";
        return;
    }

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX_SIZE - 1;
    else
        rear--;
}

void dQ::display()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    int i = front;
    do
    {
        cout << elements[i].data << " ";
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);

    cout << endl;
}

int main()
{
    dQ d;
    d.enrear();
    d.enrear();
    d.enfront();
    d.enrear();
    d.enfront();
    d.enfront();
    d.display();
    cout << "\n";
    d.derear();
    d.defront();
    d.display();
    cout << "\n";
    return 0;
}