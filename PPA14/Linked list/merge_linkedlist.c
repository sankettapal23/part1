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
void merge(struct node*,struct node*,struct node**);



int main()
{   int choice;
    struct node* first_node1=NULL;
    struct node* first_node2=NULL;
    struct node* first_node3=NULL;

    do
    {
        puts("1. Create linked list 1");
        puts("2. Create linked list 2");
        puts("3. display linked list 1");
        puts("4. display linked list 2");
        puts("5. Merge Two Linked lists");
        puts("0. Exit");

        puts("Enter your choice \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatlinklist(&first_node1);
                break;
            case 2:creatlinklist(&first_node2);
                break;    
            case 3:displaylinklist(first_node1);
                break;
            case 4:displaylinklist(first_node2);
                break;
            case 5:merge(first_node1,first_node2,&first_node3);
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

void merge(struct node* head1,struct node* head2,struct node** head3)
{
    struct node* trav1=head1;
    struct node* trav2=head2;
    struct node* new =*head3;
    
    while(trav1->next!=NULL && trav2->next!=NULL)
    {
        if(trav1->data > trav2->data)
        {
            new->data=trav2->data;
            new=new->next;
            trav2=trav2->next;
        }
        else if(trav1->data==trav2->data)
        {
            new->data=trav1->data;
            new=new->next;
            trav1=trav1->next;
            trav2=trav2->next;
        }
        else 
        {
            new->data=trav1->data;
            new=new->next;
            trav1=trav1->next;
        }
        
    }
    if(trav1->next==NULL)
    {
        while(trav2!=NULL)
        {
            new->data=trav2->data;
            new=new->next;
            trav2=trav2->next;
        }
    }
    if(trav2->next==NULL)
    {
        while(trav1!=NULL)
        {
            new->data=trav1->data;
            new=new->next;
            trav1=trav1->next;
        }
    }
    printf("Linked List after sorting \n");
    displaylinklist(*head3);

}

