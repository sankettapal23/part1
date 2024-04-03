#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createnode();
void creatlinkedlist(struct node**,struct node**);
void displaylinkedlist(struct node* );
void displayreverse(struct node*);
void insertatfirst(struct node**,struct  node**);
void insertatlast(struct node**,struct  node**);

void main()
{
    struct node* first=NULL;
    struct node* last=NULL;
    int choice;
    do
    {
        puts("1. create linked list");
        puts("2. display forward linked list");
        
        puts("3. insert at last ");
        puts("4. insert at first ");
        puts("5. Display reverse linked list");
        puts("0. exit");

        puts("Enter your choice");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:creatlinkedlist(&first,&last);
                break;
            case 2:displaylinkedlist(first);
                break;
            
            case 3:insertatlast(&first,&last);
                break;
            case 4:insertatfirst(&first,&last);
                break;
            case 5:displayreverse(last);
                break;

            case 0:puts("Exit");
                break;
        }
    }while(choice !=0);

}

struct node* createnode()
{
    struct node* newnode=NULL;
    int value;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        puts("Error in MEmory Allocation");
        exit(EXIT_FAILURE);
    }

    else
    {
        puts("Enter a data ");
        scanf("%d", &value);

        newnode->prev=NULL;
        newnode-> data=value;
        newnode->next=NULL;
    }
    return (newnode);
}

void creatlinkedlist(struct node** head, struct node** tail)
{
    struct  node* newnode=NULL;
    newnode=createnode();
    
    if(*head == NULL && *tail== NULL)
    {
        *head=*tail=newnode;
        (*head)->prev=*tail;
        (*tail)->next=*head;
    }
    else
    {
        newnode->prev=*tail;
        newnode->next=*head;
        (*tail)->next= newnode;
        (*head)->prev=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
    
}

void displaylinkedlist(struct node* head)
{   
    struct node* tempnode=head;
    do
    {
        printf("%d\n", tempnode->data);
        tempnode=tempnode->next;
    }while(tempnode!=head);

    
    printf("\n\n");
}

void displayreverse(struct node* tail)
{   
    struct node* tempnode=tail;
    do
    {
        printf("%d\n", tempnode->data);
        tempnode=tempnode->prev;
    }while(tempnode!=tail);

    
    printf("\n\n");
}

void insertatlast(struct node**head,struct node**tail)
{
    struct node* newnode=NULL;
    newnode=createnode();

    if(*head == NULL && *tail== NULL)
    {
        *head=*tail=newnode;
        (*head)->prev=*tail;
        (*tail)->next=*head;
    }
    else
    {
        newnode->prev=*tail;
        newnode->next=*head;
        (*tail)->next= newnode;
        (*head)->prev=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
}

void insertatfirst(struct node**head,struct node**tail)
{
    struct node* newnode=NULL;
    newnode=createnode();

    if(*head==NULL && *tail== NULL)
    {
        *head=*tail=newnode;
    }
    else
    {
         newnode->prev=*tail;
        newnode->next=*head;
        (*tail)->next= newnode;
        (*head)->prev=newnode;
        newnode->prev=*tail;
        *head=newnode;
    }

}
