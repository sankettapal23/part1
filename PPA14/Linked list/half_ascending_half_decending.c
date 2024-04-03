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
void sort(struct node**);


int main()
{   int choice;
    struct node* first_node=NULL;
    do
    {
        puts("1. create linked list");
        puts("2. display linked list");
        puts("3. Sort the linked list into half acending and half decending");
        puts("0. Exit");

        puts("Enter your choice \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatlinklist(&first_node);
                break;
            case 2:displaylinklist(first_node);
                break;
            case 3:sort(&first_node);
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

int countnode(struct node* head)
{
    int count=0;
    while(head != NULL)
    {
        count++;
        head=head->next;
    }
    return(count);
}

void sort(struct node** head)
{
    struct node* trav1=*head;
    struct node* temp1=trav1;
    struct node* trav2=(*head)->next;
    int count=countnode(*head);
    int mid=count/2;
    int i;
    int temp;

    if((*head)==NULL)
    {
        return;
    }
    
    for(trav1=(*head); trav1!=NULL ; trav1=trav1->next)
      {  for(trav2=trav1->next ; trav2!=NULL ; trav2=trav2->next)
        {
                if(trav1->data > trav2->data)
                {
                    temp=trav1->data;
                    trav1->data=trav2->data;
                    trav2->data=temp;
                }
        }
      }    

    for(i=0 ; i<mid ; i++)
    {
        temp1=temp1->next;
    }

    for(trav1=temp1; trav1!=NULL ; trav1=trav1->next)
      {  for(trav2=trav1->next ; trav2!=NULL ; trav2=trav2->next)
        {
                if(trav1->data < trav2->data)
                {
                    temp=trav1->data;
                    trav1->data=trav2->data;
                    trav2->data=temp;
                }
        }
      } 

    printf("Linked List after sorting \n");
    displaylinklist(*head);

}



