#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int* arr;
    int capacity;
    int front;
    int rear;
};

struct Queue* create_queue();
void enqueue (struct Queue*,int);
int is_full(struct Queue*);
void dequeue(struct Queue*);
int is_empty(struct Queue*);
void display(struct Queue*);
void get_front(struct Queue*);
void get_rear(struct Queue*);

void main()
{
    struct Queue* queue=NULL;
    queue=create_queue();
    int choice,data;
    do{
        puts("1. enqueue");
        puts("2. Dequeue");
        puts("3. display");
        puts("4. get front");
        puts("5. get rear");
        puts("0. Exit");

        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                puts("Enter data");
                scanf("%d",&data);
                enqueue(queue,data);
                break;
            case 2: dequeue(queue);
                break;
            case 3: display(queue);
                break;
            case 4: get_front(queue);
                break;
            case 5: get_rear(queue);
                break;
        }

    }while(choice !=0);
}

struct Queue* create_queue()
{
    int cap;
    struct Queue*queue=NULL;
    queue=(struct Queue*)malloc(sizeof(struct Queue));

    if(queue == NULL)
    {
        puts("Error in Memory Allocation");
        exit(EXIT_FAILURE);
    }

    puts("Enter capacity");
    scanf("%d",&cap);
    queue->capacity=cap;
    queue->arr=(int*)malloc(queue->capacity*sizeof(int));
    if(queue->arr == NULL)
    {
        puts("Error in Memory Allocation");
        exit(EXIT_FAILURE);
    }
    queue->front=-1;
    queue->rear=-1;

    return (queue);
}

void enqueue(struct Queue* queue,int data)
{
    if(is_full(queue))
    {
        puts("Queue is Full");
        return;
    }

    (queue->rear)++;
    queue->arr[queue->rear]=data;
}

int is_full(struct Queue* queue)
{
    return queue->rear == (queue->capacity)-1;
}

void dequeue(struct Queue * queue)
{
    if(is_empty(queue))
    {
        puts("Queue is Empty");
        return;
    }

    (queue->front)++;
    printf("Dequeued Element =%d\n",queue->arr[queue->front]);
    
}

int is_empty(struct Queue* queue)
{
    return queue->front == queue->rear;
}

void display(struct Queue* queue)
{
    int i;
    if(is_empty)
    {
        puts("Queue is Empty");
        return;
    }
    for(i=queue->front+1; i<=queue->rear;i++)
    {
        printf("%d",queue->arr[i]);
    }
}

void get_front(struct Queue* queue)
{
    if(is_empty)
    {
        puts("Queue is Empty");
        return;
    }
    printf("Element at Front is =%d\n",queue->arr[queue->front]);
}

void get_rear(struct Queue* queue)
{
    if(is_empty)
    {
        puts("Queue is Empty");
        return;
    }
    printf("Element at Rear is =%d\n",queue->arr[queue->rear]);
}

