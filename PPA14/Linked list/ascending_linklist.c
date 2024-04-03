#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;

};


void creatlinklist(struct node**);
struct node* createnode();
void displaylinklist(struct node*);
void acendingorder(struct node**);



int main()
{   int choice;
    struct node* first_node=NULL;
    do
    {
        puts("1. create linked list");
        puts("2. display linked list");
        puts("3. Ascending Order of link list");
        puts("0. Exit");
        

        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatlinklist(&first_node);
                break;
            case 2:displaylinklist(first_node);
                break;
            case 3:acendingorder(&first_node);
                break;

        }
    }while(choice!=0);
    return (0);
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
    if(head==NULL)
    {
    printf("List is Empty");
    }
    else
    {

    while(head!=NULL)
    {
        printf("\n%d ", head->data);
        head=head->next;
    }
    
    }
    printf("\n\n");
}

void acendingorder(struct node** head)
{
    struct node* travnode1=*head;
    struct node* travnode2=(*head)->next;
    int temp;

    if((*head)==NULL)
    {
        return;
    }
    
    for(travnode1=(*head); travnode1!=NULL ; travnode1=travnode1->next)
      {  for(travnode2=travnode1->next ; travnode2!=NULL ; travnode2=travnode2->next)
        {
                if(travnode1->data > travnode2->data)
                {
                    temp=travnode1->data;
                    travnode1->data=travnode2->data;
                    travnode2->data=temp;
                }
        }
      }
    printf("Linked List after sorting \n");
    displaylinklist(*head);
}


