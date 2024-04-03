#include<stdio.h>
#include<stdlib.h>

struct STACK
{
    int top;
    int capacity;
    int *arr;
};

struct STACK* createstack();
void push (struct STACK*);
int is_overflow(struct STACK*);
void pop (struct STACK*);
int is_underflow(struct STACK*);
void display (struct STACK*);


int main()
{
    int choice;
    struct STACK* stack=NULL;
    stack=createstack();
    do
    {
        puts("\n1. Push Element in Stack");
        puts("2. Pop Element in Stack");
        puts("3. Display a Stack");
        puts("0. Exit");

        puts("Enter Your Choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: push(stack);
                break;
            case 2: pop(stack);
                break;
            case 3: display(stack);
                break;
            case 0:
                puts("Exit");
                break;
        }

    }while(choice!=0);
}

struct STACK* createstack()
{
    int cap;
    struct STACK* stack=NULL;
    stack=(struct STACK*)malloc(sizeof(struct STACK));

    puts("Enter Capacity of stack ");
    scanf("%d",&cap);

    if(stack==NULL)
    {
        puts("Error in memory Allocation");
        exit(EXIT_FAILURE);
    }
    else
    {
        stack->capacity=cap;
        stack->arr=(int*)malloc(stack->capacity*sizeof(int));
        stack->top=-1;
    }
    return stack;
}

void push(struct STACK* stack)
{
    int data;

    puts("Enter Data ");
    scanf("%d", &data);

    if(is_overflow(stack))
    {
        puts("stack is Overflow");
        return;
    }
    else
    {
        stack->arr[++(stack->top)]= data;
    }
}

int is_overflow(struct STACK* stack)
{
    return stack->top==stack->capacity-1;
}

void pop(struct STACK* stack)
{
    if(is_underflow(stack))
    {
        puts("Stack is Underflow");
        return;
    }
    else
    {
        printf("Popped Element is=%d \n",stack->arr[stack->top]);
        (stack->top)--;
    }
}

int is_underflow(struct STACK* stack)
{
    return stack->top==-1;
}

void display(struct STACK* stack)
{
    int i;
    if(is_underflow(stack))
    {
        puts("Stack is Underflow");
        return;
    }

    for(i=0 ; i <= stack->top ; i++)
    {
        printf("%d =>",stack->arr[i]);
    }
    printf("\n");
}