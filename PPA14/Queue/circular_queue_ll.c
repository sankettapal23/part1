#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
struct Queue
{
    struct node* front;
    struct node* rear;
};

void dequeue(struct Queue*);
void enqueue(struct Queue*);
void display(struct Queue*);
struct Queue* create_queue();
struct node* createnode();

void main()
{
    int choice;
    struct Queue* cqueue= NULL;
    cqueue=create_queue();

    do
    {
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. display");
        puts("0. Exit");
        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(cqueue);
                break;
            case 2: dequeue(cqueue);
                break;
            case 3: display(cqueue);
                break;
        }
       
    } while (choice != 0);
    
}

struct node* createnode()
{   int data;
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode== NULL)
    {
        puts("Error in emory allocation");
        exit(EXIT_FAILURE);
    }
    puts("Enter data ");
    scanf("%d",&data);

    newnode -> data= data;
    newnode -> next = NULL;

    return newnode;
}


struct Queue* create_queue()
{
    struct Queue* cqueue=NULL;
    cqueue= (struct Queue*)malloc(sizeof(struct Queue));
    if(cqueue== NULL)
    {
        puts("Error in emory allocation");
        exit(EXIT_FAILURE);
    }

    cqueue->front == NULL;
    cqueue -> rear == NULL;

    return cqueue;
}

void enqueue(struct Queue* cqueue)
{
    struct node* newnode=NULL;
    newnode=createnode(); 

    if(cqueue -> front==NULL && cqueue -> rear== NULL)
    {
        cqueue->front =newnode;
        cqueue -> rear =newnode;
        cqueue -> rear -> next = cqueue -> front;

    }
    cqueue -> rear -> next = newnode;
    cqueue -> rear = newnode;
    cqueue -> rear -> next = cqueue -> front;
}

void dequeue( struct Queue* cqueue)
{
    struct node* temp =NULL;
    if(cqueue-> front ==NULL && cqueue-> rear ==NULL)
    {
        puts("Queue is Empty");
    }
    else if (cqueue-> front == cqueue-> rear )
    {
        cqueue-> front= NULL;
        cqueue-> rear = NULL;
        free (cqueue->front);
    }
    else
    {
        temp = cqueue -> front;
        cqueue->front = cqueue->front->next;
        cqueue->rear->next = cqueue->front;
        free (temp);
    }
    
}

void display(struct Queue* cqueue)
{
    if(cqueue -> front==NULL && cqueue -> rear== NULL)
    {
        puts("Queue is Empty");
        return;
    }
    do
    {
     printf("%d\n",cqueue->front->data);
     cqueue->front=cqueue->front->next; 
    
    }while(cqueue->front != cqueue->rear);
}