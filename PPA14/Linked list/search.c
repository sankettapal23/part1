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
void search(struct node*);



int main()
{   int choice;
    struct node* first_node=NULL;
    do
    {
        puts("1. create linked list");
        puts("2. display linked list");
        puts("3. Search an Element in link list");
        puts("0. Exit");

        puts("Enter your choice \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatlinklist(&first_node);
                break;
            case 2:displaylinklist(first_node);
                break;
            case 3:search(first_node);
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
        printf("%d\n", head->data);
        head=head->next;
    }
    }
    printf("\n\n");
}

void search(struct node* head)
{
    int key;
    int flag=0;
    struct node* travnode=head;

    printf("Enter The element want to search in linked list \n");
    scanf("%d",&key);

    while(travnode !=NULL)
    {
        if(travnode->data == key)
        {
            flag=1;
            printf("Given Element is present in linked list\n\n");
            break;
        }
        travnode=travnode->next;
    }
    if(flag==0)
        {
            printf("Given Element is NOT present in linked list\n\n");

        }

}

