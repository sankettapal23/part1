#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node* next;
};

void enqueue(struct node**);
void dequeue(struct node**);
void display(struct node*);
void peak(struct node*);

void main()
{
    struct node* front =NULL;
    int choice;
    do
    {
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. Display");
        puts("4. Peak");
        puts("0. Exit");

        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(&front);
                break;
            case 2: dequeue(&front);
                break;
            case 3: display(front);
                break;
            case 4: peak(front);
                break;
        }
    } while (choice!=0);
    
}

void enqueue(struct node** head)
{
    int data, priority;
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter data ");
    scanf("%d",&data);
    puts("Enter priority");
    scanf("%d",&priority);

    newnode->data=data;
    newnode->priority=priority;
    newnode->next=NULL;
    
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    if((*head)->priority > newnode->priority)
    {
        newnode->next = *head;
        (*head)=newnode;
    }
    else
    {
        struct node* current=*head;
        struct node* prev=NULL;
        while(current != NULL && current->priority < newnode->priority)
        {
            prev= current;
            current =current->next ;
        }
        newnode->next=current;
        prev->next=newnode;
    }
}

void dequeue(struct node** head)
{
    struct node* temp=NULL;
    if((*head==NULL))
    {
        puts("Queue is Empty");
        return;
    }
    temp=(*head);
    printf("Dequeued element = %d , priority = %d\n ",temp->data,temp->priority);
    (*head)=(*head)->next;
    free(temp);
}

void display(struct node* head)
{
    struct node* temp= head;
    if((head==NULL))
    {
        puts("Queue is Empty");
        return;
    }
    while(temp != NULL)
    {
        printf("Element =%d, Priority= %d\n",temp->data,temp->priority);
        temp=temp->next;
    }

}

void peak(struct node* head)
{
    printf("Peaked element=%d , priority=%d\n",head->data,head->priority);
}
