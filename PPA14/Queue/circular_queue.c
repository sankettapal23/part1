#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int*arr;
    int capacity;
    int size;
    int front;
    int rear;
};

struct Queue* create_queue();
void enqueue(struct Queue*);
void dequeue(struct Queue*);
int is_full(struct Queue*);
int is_empty(struct Queue*);
void display(struct Queue*);

void main()
{
    struct Queue*c_queue = NULL;
    c_queue = create_queue();
    int choice;

    do
    {
        puts("1. Enqueue ");
        puts("2. Dequeue");
        puts("3. Display");
        puts("0. Exit");

        puts("Enter Your Choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(c_queue);
                break;
            case 2: dequeue(c_queue);
                break;
            case 3: display(c_queue);
                break;
        }
        
    } while (choice != 0);
    
}

struct Queue* create_queue()
{
    int cap;
    struct Queue* c_queue = NULL;
    c_queue=(struct Queue*)malloc(sizeof(struct Queue));
    
    if(c_queue == NULL)
    {
        puts("Error in Memory Allocation");
        exit(EXIT_FAILURE);
    }

    puts("Enter capacity");
    scanf("%d",&cap);

    c_queue -> capacity = cap;
    c_queue -> arr =(int*)malloc(c_queue->capacity*sizeof(int));
    if(c_queue -> arr == NULL)
    {
        puts("Error in Memory Allocation");
        exit(EXIT_FAILURE);
    }
    c_queue -> size = 0;
    c_queue -> front = -1;
    c_queue -> rear = -1;

    return c_queue;
}


void enqueue(struct Queue* c_queue)
{  
    int data;
    if(is_full(c_queue))
    {
        puts("Queue is FULL");
        return;
    }
    puts("Enter Data");
    scanf("%d",&data);

    c_queue -> rear = (c_queue -> rear +1)% c_queue -> capacity;
    c_queue -> arr[c_queue -> rear] = data;
    (c_queue -> size)++ ;
}

int is_full(struct Queue* queue)
{
    return queue -> size == queue -> capacity;
}

void dequeue(struct Queue* c_queue)
{
    if(is_empty(c_queue))
    {
        puts("Queue is Empty");
        return;
    }

    
    c_queue -> front = (c_queue -> front +1)% c_queue -> capacity;
    (c_queue -> size)-- ;
}

int is_empty(struct Queue* queue)
{
    return queue->front = queue->rear = -1;
}

void display(struct Queue* queue)
{
    int i;
    
    if(is_empty(queue))
    {
        puts("Queue is Empty");
        return;
    }
    for(i=queue->front+1; i<=queue->rear;i++)
    {
        printf("%d",queue->arr[i]);
    }
}