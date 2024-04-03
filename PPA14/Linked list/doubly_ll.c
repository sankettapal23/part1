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
void displayreverselinklist(struct node* );
void insertatfirst(struct node**,struct  node**);
void insertatlast(struct node**,struct  node**);
void insertatpos(struct node**,struct  node**);
int countnode(struct node*);
void deleteatfirst(struct node**,struct node**);
void deleteatlast(struct node**,struct node**);
void deleteatpos(struct node**,struct node**);
void search(struct node*,struct node*);




void main()
{
    struct node* first=NULL;
    struct node* last=NULL;
    int choice;
    do
    {
        puts("1. create linked list");
        puts("2. display forward linked list");
        puts("3. display backward linked list");
        puts("4. insert at first ");
        puts("5. insert at last ");
        puts("6. insert at position ");
        puts("7. Delete at first");
        puts("8. Delete at last");
        puts("9. Delete at position");
        puts("10. search element in linked list");


        puts("0. exit");

        puts("Enter your choice");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:creatlinkedlist(&first,&last);
                break;
            case 2:displaylinkedlist(first);
                break;
            case 3:displayreverselinklist(last);
                break;
            case 4:insertatfirst(&first,&last);
                break;
            case 5:insertatlast(&first,&last);
                break;
            case 6:insertatpos(&first,&last);
                break; 
            case 7:deleteatfirst(&first,&last);
                break; 
            case 8:deleteatlast(&first,&last);
                break;
            case 9: deleteatpos(&first,&last);
                break; 
            case 10:search(first,last);
                break;  
               
            case 0: 
                puts("Exit");
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
    }
    else
    {
        (*tail)->next= newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
    
}

void displaylinkedlist(struct node* head)
{   if(head==NULL)
    {
        puts("List is Empty");
    }
    while(head != NULL)
    {
        printf("%d=> ",head->data);
        head=head-> next;
    }
}

void displayreverselinklist(struct node* tail)
{   
    if(tail==NULL)
    {
        puts("List is Empty");
    }
    while(tail != NULL)
    {
        printf("%d=>",tail->data);
        tail=tail->prev;
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
        newnode->next=*head;
        (*head)->prev = newnode;
        *head=newnode;
    }

}

void insertatlast(struct node**head,struct node**tail)
{
    struct node* newnode=NULL;
    newnode=createnode();

    if(*head==NULL && *tail== NULL)
    {
        *head=*tail=newnode;
    }
    else
    {
        (*tail)->next=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }

}

void insertatpos(struct node** head,struct  node** tail)
{
    int pos,n,i;
    struct node* travnode=*head;
    struct node* newnode=NULL;
    
    
    printf("Enter value of position :\n");
    scanf("%d",&pos);

    n=countnode(*head);

    if(pos==1)
    {
        insertatfirst(head,tail);
    }

    else if(pos ==n+1)
    {
        insertatlast(head,tail);
    }

    else if(pos<=0 || pos>n+1)
    {
        puts("Invalid value of position");
        insertatpos(head,tail);
    }

    else
    {
        struct node* newnode=createnode();
        for(i=1; i<pos; i++)
        {
            travnode=travnode->next;
        }
        newnode->prev=travnode->prev;
        newnode->next=travnode;

        travnode->prev->next=newnode;
        travnode->prev=newnode;
    }

}

int countnode(struct node* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
    
}   

void deleteatfirst(struct node** head,struct node** tail)
{   
    struct node* tempnode=*head;
    if(*head == NULL && *tail==NULL)
    {
        puts("Linked list not available");
        return;
    }
    else if((*head)-> next ==NULL)
    {
        free(*head);
        *head=*tail=NULL;
    }
    else
    {
       *head=(*head)->next;
       (*head)->prev=NULL;
       free(tempnode);
       
    }
}

void deleteatlast(struct node** head ,struct node** tail)
{
    struct node* tempnode=*tail;
    if(*head == NULL && *tail==NULL)
    {
        puts("Linked list not available");
        return;
    }
    else if((*tail)-> prev ==NULL)
    {
        free(*tail);
        *head=*tail=NULL;
    }
    else
    {
        (*tail)=(*tail)->prev;
        (*tail)->next=NULL;
        free(tempnode);
    }
}

void deleteatpos(struct node**head,struct node**tail)
{
    int pos,n,i;
    struct node* trav=*head;
    puts("ENTER VALUE OF POSITION -");
    scanf("%d",&pos);

    n=countnode(*head);

    if(pos==1)
    {
        deleteatfirst(head,tail);
    }
    else if(pos==n)
    {
        deleteatlast(head,tail);
    }
    else if(pos<1 || pos>n)
    {
        puts("INVALID POSITION");
        deleteatpos(head,tail);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            trav=trav->next;
        }
        trav->prev->next=trav->next;
        trav->next->prev=trav->prev;

        free(trav);
    }
}

void search(struct node* head,struct node* tail)
{
    int no;
    
    int flag=0;
    puts("ENTER THE ELEMENT WANT TO SEARCH ");
    scanf("%d",&no);

    do
    {
        if(head->data==no || tail->data==no)
        {
            flag=1;
            puts("ELEMENT FOUND");
            break;
        }
        else
        {
            head=head->next;
            tail=tail->prev;
        }
    }while(head->prev == tail->next);

    if(flag==0)
    {
        puts("ELEMENT NOT FOUND");
    }
}