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
int countnode(struct node*);
void replacenode(struct node**);
void deleteatfirst(struct node**);
void deleteatlast(struct node**);
void deleteatpos(struct node**);
void reverselinklist(struct node*);


int main()
{   int choice;
    struct node* first_node=NULL;
    do
    {
        puts("1. creat linked list");
        puts("2. display linked list");
        puts("3. Insert st first ");
        puts("4. Insert at last");
        puts("5. Insert at specific position");
        puts("6. replace node");
        puts("7. Delete at first");
        puts("8. Delete at last");
        puts("9. Delete at specific position");
        puts("10. Reverse link list");
        puts("0. exit");

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
            case 6:replacenode(&first_node);
                break;
            case 7:deleteatfirst(&first_node);
                break;   
            case 8:deleteatlast(&first_node);
                break;    
            case 9:deleteatpos(&first_node);
                break;
            case 10:reverselinklist(first_node);
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

void insertatfirst(struct node** head)
{
    struct node* new_node=NULL;
    new_node=createnode();
    new_node->next=*head;
    *head=new_node;
}

void insertatlast(struct node** head)
{
    creatlinklist(head);
}

void insertatpos(struct node** head)
{
    int pos,n,i;
    printf("Enter the position where you want to add new element -");
    scanf("%d",&pos);

    n=countnode(*head);

    if(pos==1)
    {
        insertatfirst(head);
    }

    else if(pos == n+1)
    {
        insertatlast(head);
    }

    else if(pos<1 || pos>n+1)
    {
        printf("Invalid position");
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
    int count=0;
    while(head != NULL)
    {
        count++;
        head=head->next;
    }
    return(count);
}

void replacenode(struct node** head)
{
    int pos,n,i;
    printf("Enter the position where you want to replace element -");
    scanf("%d",&pos);

    n=countnode(*head);

    if(pos==1)
    {
        struct node* new_node=NULL;
        new_node=createnode();

        new_node->next=(*head)->next;
        *head=new_node;
    }

    else if(pos<1 || pos>n)
    {
        printf("Invalid position");
        replacenode(head);
    }

    else
    {
        struct node* travnode = *head;
        struct node*new_node = NULL;
        new_node=createnode();

        for(i=0; i<pos-1; i++)
        {
            travnode=travnode->next;
        }
        new_node->next =travnode->next->next;
        travnode->next=new_node;        

    }
    
}

void deleteatfirst(struct node** head)
{
    struct node* temp= *head;
    *head=(*head)->next;
    free(temp);
}

void deleteatlast(struct node**head)
{
    struct node* travnode=*head;
    if(*head==NULL)
    {
        printf("already empty");

    }
    else if((*head)->next==NULL)
    {
        free(*head);
    }
    else
    {
        while(travnode->next->next!=NULL)
        {
            travnode=travnode->next;
        }
        free(travnode->next);
        travnode->next=NULL;
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

void reverselinklist(struct node* head)
{
    if(head==NULL)
    {
        return;
    }
    reverselinklist(head->next);
    printf("%d =>",head->data);
}