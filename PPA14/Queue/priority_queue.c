#include<stdio.h>
#include<stdlib.h>

struct element
{
    int data;
    int priority;
};
struct PQueue
{
    struct element* arr;
    int capacity;
    int size;
};

struct PQueue* create_queue();
void enqueue(struct PQueue* );
int is_full(struct PQueue* );
void display(struct PQueue* );
void dequeue(struct PQueue* );
void peak(struct PQueue* );
int is_empty(struct PQueue* );


void main()
{
    struct PQueue* pq=NULL;
    pq=create_queue();
    int choice;
    do
    {
        puts("1. Enqueue");
        puts("2. Display");
        puts("3. Dequeue");
        puts("4. Peak element");
        puts("0. Exit");

        puts("Enter your Choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(pq);
                break;
            case 2: display(pq);
                break;
            case 3: dequeue(pq);
                break;
            case 4:peak(pq);
                break;
        }
    } while (choice!=0);
    
}

struct PQueue* create_queue()
{
    int capacity;
    struct PQueue* pq= NULL;
    pq=(struct PQueue*)malloc(sizeof(struct PQueue));
    if(pq == NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);
    }
    puts("Enter Capacity ");
    scanf("%d",&capacity);
    pq->capacity=capacity;
    pq->arr=(struct element*)malloc(pq->capacity*sizeof(struct element));
    if(pq->arr == NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);
    }
    pq->size=0;

    return pq;
}

void enqueue(struct PQueue* pq)
{
    int data,priority,i;
    if(is_full(pq))
    {
        puts("Priority Queue is FULL");
        return;
    }
    puts("Enter Data ");
    scanf("%d",&data);
    puts("Enter Priority");
    scanf("%d",&priority);
    (pq->arr[pq->size]).data = data;
    (pq->arr[pq->size]).priority = priority;
    (pq->size)++;
    struct element temp;
    for(i = pq->size-1; i > 0 ; i--)
    {
        if((pq->arr[i]).priority > (pq->arr[i-1]).priority)
        {
            temp = pq->arr[i];
            pq->arr[i]=pq->arr[i-1];
            pq->arr[i-1] = temp;
        }
    }
}

int is_full(struct PQueue* pq)
{
    return pq->size == pq->capacity;
}

void display(struct PQueue* pq)
{
    int i;
    if(is_empty(pq))
    {
        puts("Queue is Empty");
        return;
    }
    for(i=0; i<pq->size; i++)
    {
        printf("Data= %d  Priority=%d\n",(pq->arr[i]).data , (pq->arr[i]).priority);
    }
}

void dequeue(struct PQueue* pq )
{
    int i;
    if(is_empty(pq))
    {
        puts("Queue is Empty");
        return;
    }
    for(i=0;i<pq->size-1;i++)
    {
        pq->arr[i]=pq->arr[i+1];
    }
    (pq->size)--;
}

int is_empty(struct PQueue* pq)
{
    return pq->size==0;
}

void peak(struct PQueue* pq)
{
    if(is_empty(pq))
    {
        puts("PQueue is empty");
        return;
    }
    printf("Peaked Element is=%d\n",(pq->arr[0]));
}
