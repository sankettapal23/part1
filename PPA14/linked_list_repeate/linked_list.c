#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createnode();
void createlinklist(struct node**);
void displaylinklist(struct node*);
void insertatfirst(struct node**);
void insertatlast(struct node**);
void insertatpos(struct node**);
int countnode(struct node*);
void reverse(struct node*);

struct node* createnode()
{   
    int value;
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);

    }
    else
    {
        puts("Enter a data");
        scanf("%d",&value);

        newnode->data=value;
        newnode->next=NULL;

    }
    return(newnode);
}

int main()
{
    struct node* first=NULL;
    int choice;
    do
    {
        puts("1. create linked list");
        puts("2. Display linked list");
        puts("3. Insert at First");
        puts("4. Insert at last");
        puts("5. Insert at pos");
        puts("6. reverse linked list");
        puts("0. Exit");

        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
         case 1: createlinklist(&first);
            break;
         case 2: displaylinklist(first);
            break;   
         case 3: insertatfirst(&first);
            break;
         case 4: insertatlast(&first);
            break;
         case 5: insertatpos(&first);
            break;    
         case 6: reverse(first);
            break;         
        }
    }while( choice != 0);
    return(0);
}

void createlinklist(struct node** head)
{
    struct node* tempnode=NULL;
    struct node* travnode=*head;
    tempnode = createnode();

    if(*head==NULL)
    {
        *head = tempnode;
    }
    else
    {
        while(travnode->next!=NULL)
        {
            travnode = travnode->next;
        }
        travnode->next = tempnode;

    }
}

void displaylinklist(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d => ",head->data);
        head=head->next;
    }
}

void insertatfirst(struct node** head)
{
    struct node* newnode=NULL;
    newnode=createnode();

    newnode->next=*head;
    *head=newnode;

}

void insertatlast(struct node** head)
{
    createlinklist(head);
}

void insertatpos(struct node** head)
{
    int pos,n,i;
    struct node* newnode=NULL;
    struct node* travnode=*head;
    puts("Enter value of position ");
    scanf("%d",&pos);

    n=countnode(*head);

    if(pos==1)
    {
        insertatfirst(head);
    }
    else if(pos==n+1)
    {
        insertatlast(head);
    }
    else if(pos<1 || pos>n+1)
    {
        puts("Invalid vaue of position");
        insertatpos(head);
    }
    else
    {   
        newnode= createnode();

        for(i=0;i<pos-1;i++)
        {
            travnode=travnode->next;
        }
        newnode->next=travnode->next;
        travnode->next=newnode;

    }

}


int countnode(struct node* head)
{
    int count=0;

    while(head!= NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

void reverse(struct node* head)
{
    if(head==NULL)
    {
        return;
    }
    reverse(head->next);
    printf("%d => ",head->data);
}
