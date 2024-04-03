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
void insertatfirst(struct node**);
void insertatlast(struct node**);
void insertatpos(struct node**);
int countnode(struct node* );
void deleteatfirst(struct node**);
void deleteatlast(struct node**);
void deleteatpos(struct node**);

int main()
{   int choice;
    struct node* first_node=NULL;
    do
    {
        puts("1. Create linked list");
        puts("2. Display linked list");
        puts("3. Insert at first");
        puts("4. Insert at last");
        puts("5. Insert at position");
        puts("6. Delete at first");
        puts("7. Delete at last");
        puts("8. Delete at position");

        puts("0. Exit");
        puts("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatlinklist(&first_node);
                break;
            case 2:displaylinklist(first_node);
                break;
            case 3:insertatfirst(&first_node);
                break;
            case 4:insertatlast(&first_node);
                break;
            case 5:insertatpos(&first_node);
                break;  
            case 6:deleteatfirst(&first_node);
                break;
            case 7:deleteatlast(&first_node);
                break;
            case 8:deleteatpos(&first_node);
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

void insertatfirst(struct node** head)
{
    struct node* newnode=NULL;
    newnode=createnode();

    struct node* travnode=*head;

    if(*head==NULL)
    {
        *head=newnode;
        (*head)->next=newnode;
    }
    else
    {
        while(travnode->next!=*head)
        {
            travnode=travnode->next;
        }
        
        travnode->next=newnode;
        newnode->next=*head;
        *head=newnode;
    }

}
void insertatlast(struct node** head)
{
    struct node* newnode=NULL;
    newnode=createnode();

    struct node* travnode=*head;

    if(*head==NULL)
    {
        *head=newnode;
        (*head)->next=newnode;
    }

    else
    {
        while(travnode->next!=*head)
        {
            travnode=travnode->next;
        }
        travnode->next=newnode;
        newnode->next=*head;
    }
}

void insertatpos(struct node** head)
{
    int pos,i,n;
    puts("Enter the value of position :");
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
        puts("INVALID CHOICE FOR POSOTION ");
        insertatpos(head);
    }
    else
    {
        struct node* travnode=*head;
        for(i=1; i<pos-1 ;i++)
        {
            travnode=travnode->next;
        }
        struct node* newnode=createnode();
        newnode->next = travnode->next;
        travnode->next =newnode;
    }
}

int countnode(struct node* head)
{  
    struct node* trav=head;
    int count=0;
    do
    {
        count++;
        trav=trav->next;
    }while(trav !=head);
    return(count);
}

void deleteatfirst(struct node** head)
{
    if(*head==NULL)
    {
        puts("already empty");

    }
    else
    {   
        struct node* temp=*head;
        struct node* trav=*head;
        while(trav->next != *head);
        {
            trav=trav->next;
        }
    
        trav->next=temp->next;
        *head=trav->next;
        free(temp);
    }
}

void deleteatlast(struct node** head)
{
    struct node* travnode=*head;
    if(*head==NULL)
    {
        printf("already empty");

    }
    else if((*head)->next==*head)
    {
        free(*head);
    }
    else
    {
        while(travnode->next->next!=*head)
        {
            travnode=travnode->next;
        }
        free(travnode->next);
        travnode->next=*head;
    }
}

void deleteatpos(struct node** head)
{
    int pos,n,i;
    printf("Enter value of position want to delete -");
    scanf("%d",&pos);

    n=countnode(*head);

    if(pos==1)
    {
        deleteatfirst(head);
    }
    else if(pos==n)
    {
        deleteatlast(head);
    }
    else if(pos<1 || pos>n)
    {
        printf("Invalid choice");
        deleteatpos(head);
    }
    else
    {
        struct node* travenode=*head;
        struct node* temp=NULL;

        for(i=1; i<pos-1; i++)
        {
            travenode=travenode->next;
        }
        temp=travenode->next;
        travenode->next = temp->next;
        free(temp);
    }
}