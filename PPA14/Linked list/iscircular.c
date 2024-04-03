#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* next;
    int data;
    
};

void creatlinklist(struct node**);
void creatcircularlinklist(struct node**);
int countnode(struct node*);
struct node* createnode();
void displaylinklist(struct node*);
void iscircular(struct node*);

int main()
{
    int choice;
    struct node* first_node=NULL;

    do
    {
        puts("1. create circular linked list");
        puts("2. Create linked list");
        puts("3. display linked list");
        puts("4. check given link list is circular or not");
        puts("0. Exit");
        

        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatcircularlinklist(&first_node);
                break;
            case 2:creatlinklist(&first_node);
                break;
            case 3:displaylinklist(first_node);
                break;
            case 4:iscircular(first_node);
                break;

        }
    }while(choice!=0);
    return (0);
}

void creatcircularlinklist(struct node** head)
{
    struct node* new_node=NULL;
    struct node* tempnode=*head;
    new_node=createnode();


    if(*head==NULL)
    {
        *head=new_node;
        (*head)->next=new_node;
    }
    else
    {
        while(tempnode->next!=*head)
        {
            tempnode=tempnode->next;
        }

        tempnode->next=new_node;
        new_node->next=*head;
    }
}

void creatlinklist(struct node** head)
{
    struct node* new_node=NULL;
    struct node* tempnode=*head;
    new_node=createnode();


    if(*head==NULL)
    {
        *head=new_node;
    }
    else
    {
        while(tempnode->next!=NULL)
        {
            tempnode=tempnode->next;
        }

        tempnode->next=new_node;
    }
}

struct node* createnode()
{   int value;
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        puts("Error in Memory Alloction");
        exit(EXIT_FAILURE);
    }
    else
    {
        puts("Enter data\n");
        scanf("%d",&value);

        newnode->data=value;
        newnode->next=NULL;
    }
        return newnode;
    
}

void displaylinklist(struct node* head)
{
    
    struct node* tempnode=head;
    do
    {
        printf("%d\n", tempnode->data);
        tempnode=tempnode->next;
    }while(tempnode!=head);

    
    printf("\n\n");
}

void iscircular(struct node* head)
{
    struct node* travnode=head;
    
    int n=countnode(head);
    int i;
    for(i=0;i<n-1;i++)
    {
        travnode=travnode->next;
    }
    if(travnode->next==NULL)
    {
        puts("Linked list is not Circular");
    }
    if(travnode->next=head)
    {
        puts("Linked list is circular");
    }

    
}

int countnode(struct node* head)
{   struct node* trav=head;
    int count=0;
    do
    {
        count++;
        trav=trav->next;
    }while(trav != NULL || trav != head);
    
    return(count);
}
