#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct Deque
{
    struct node* front;
    struct node* rear;
};

struct node* createnode();
struct Deque* create_deque();
void insert_rear(struct Deque*);
void delete_rear(struct Deque*);
void insert_front(struct Deque*);
void delete_front(struct Deque*);
void display(struct Deque*);
int is_empty(struct Deque*);

void main()
{
    struct Deque* dq=NULL;
    dq=create_deque(); 
    int choice;
    do
    {
        puts("1. Insert at rear");
        puts("2. Delete front");
        puts("3. Insert at front");
        puts("4. Delete rear");
        puts("5. Display");
        puts("0. Exit");
        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insert_rear(dq);
                break;
            case 2: delete_front(dq);
                break;
            case 3: insert_front(dq);
                break;
            case 4: delete_rear(dq);
                break;
            case 5: display(dq);
                break;
        }
    } while (choice != 0);
}

struct Deque* create_deque()
{
    struct Deque* dq=NULL;
    dq=(struct Deque*)malloc(sizeof(struct Deque));
    if(dq==NULL)
    {
        puts("ERROR IN MEMORY ALLOCATION");
        exit(EXIT_FAILURE);
    }
    dq->front=NULL;
    dq->rear=NULL;

    return dq;
}

void insert_rear(struct Deque* dq)
{
    struct node* newnode=NULL;
    newnode=createnode();
    if(is_empty(dq))
    {
        dq->front=newnode;
        dq->rear=newnode;
    }
    else
    {
        dq->rear->next=newnode;
        newnode->prev=dq->rear;
        dq->rear=newnode;
    }

}

int is_empty(struct Deque* dq)
{
    return dq->front==NULL;
}

struct node* createnode()
{   int data;
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode== NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    puts("Enter data ");
    scanf("%d",&data);

    newnode -> data= data;
    newnode -> prev = NULL;
    newnode-> next = NULL;

    return newnode;
}

void delete_front(struct Deque* dq)
{
    struct node* temp=NULL;;
    if(is_empty(dq))
    {
        puts("Deque is Empty");
        return;
    }
    temp=dq->front;
    dq -> front = dq -> front -> next;
    if(dq->front == NULL)
    {
        dq->rear=NULL;
    }
    else
    {
        dq->front->prev=NULL;
    }
    printf("Deleted element =%d\n", temp->data);
    free(temp);
}

void insert_front(struct Deque* dq)
{
    struct node* newnode=NULL;
    newnode=createnode();

    if(is_empty(dq))
    {
        dq->front=newnode;
        dq->rear=newnode;
    }
     else
    {
        newnode->next=dq->front;
        dq->front->prev=newnode;
        dq->front=newnode;
    }
}

void delete_rear(struct Deque* dq)
{
    struct node* temp=NULL;;
    if(is_empty(dq))
    {
        puts("Deque is Empty");
        return;
    }
    temp=dq->rear;
    dq->rear=dq->rear->prev;
    if(dq->rear == NULL)
    {
        dq->front=NULL;
    }
    else
    {
        dq->rear->next=NULL;
    }
    printf("Deleted Element is=%d\n",temp->data);
    free(temp);
}

void display(struct Deque* dq)
{
    struct node* temp=dq->front;
    if(is_empty(dq))
    {
        puts("Deque is empty");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("\n");
}