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

struct Queue* create_queue();
struct node* create_node();
void enqueue(struct Queue*);
void dequeue(struct Queue*);
void display(struct Queue*);


void main()
{
    int choice;
    struct Queue* queue=NULL;
    queue=create_queue();
    do
    {
        puts("1. Enqueue");
        puts("2. dequeue");
        puts("3. Display");
        puts("0. Exit");


        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(queue);
                break;
            case 2: dequeue(queue);
                break;
            case 3: display(queue);
                break;
        }
    
    } while (choice!=0);
    
}

struct node* create_node()
{
    struct node* new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);

    }
    puts("Enter data");
    scanf("%d",&(new_node->data));

    new_node->next=NULL;

    return (new_node);
}

struct Queue* create_queue()
{
    struct Queue* queue=NULL;
    queue=(struct Queue*)malloc(sizeof(struct Queue));

    queue->front=NULL;
    queue->rear=NULL;

    return (queue);
}

void enqueue(struct Queue* queue)
{
    struct node* new_node=NULL;
    new_node=create_node();

    if(queue->front == NULL && queue->rear == NULL)
    {
        queue->front=queue->rear=new_node;
        return;
    }
    (queue->rear)->next = new_node;
    queue->rear = new_node;
}

void dequeue(struct Queue* queue)
{
    struct node*temp=NULL;
    if(queue->front==NULL && queue->rear==NULL)
    {
        puts("Queue is Empty");
        return;
    }
    temp=queue->front;
    queue->front=(queue->front)->next;
    free(temp);

    if(queue->front==NULL)
    {
        queue->rear=NULL;
    }
}

void display(struct Queue* queue)
{
    int i;
    struct node* temp=queue->front;
    for(i=queue->front+1; i<=queue->rear;i++)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
