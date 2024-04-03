#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* push(struct node*);
struct node* createnode();
struct node* pop(struct node*);
int peek(struct node* );
void display(struct node*);

void main()
{
    int choice;
    struct node* top = NULL;
    
    do
    {
        puts("1. Push Element in Stack");
        puts("2. Pop Element in Stack");
        puts("3. Peek Top Element of Stack");
        puts("4. Display stack");
        puts("0. Exit");


        puts("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: top=push(top);
                break;
            case 2: top=pop(top);
                break;
            case 3: peek(top);
                break;
            case 4: display(top);
                break;
             
        }

    }while(choice!=0);
}


struct node* push(struct node* top)
{
    struct node* newnode=NULL;
    newnode=createnode();

    if(top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    return top;
}

struct node* createnode()
{
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        fprintf(stderr,"Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Enter a Data\n");
        scanf("%d",&(newnode->data));

        newnode->next=NULL;
    }
    return newnode;
}

struct node* pop(struct node* head)
{
    struct node*temp=NULL;
    if(head == NULL)
    {
        puts("Stack Underflow");

    }
    else
    {
        temp=head;
        printf("Popped Element is")
        head=head->next;
        free(temp);
    }
    return head;
}

int peek(struct node* head)
{
    printf("Peaked Element =%d\n",head->data);
}

void display(struct node* head)
{
    if(head==NULL)
    {
        puts("Stack is Empty");

    }
    else
    {
        while(head !=NULL)
        {
            printf("%d => ",head->data);
            head = head->next;
        }
        printf("\n");
    }
}