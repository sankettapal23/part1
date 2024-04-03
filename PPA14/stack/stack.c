#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int capacity;       
};

struct Stack* createstack();
void push(struct Stack*);
int is_overflow(struct Stack*);
void display(struct Stack*);
void pop(struct Stack*);
int is_underflow(struct Stack*);
void peak(struct Stack*);

void main()
{   
    int choice;
    struct Stack* stack=NULL;
    stack=createstack();
    do
    {
        puts("1. Push element");
        puts("2. Pop element");
        puts("3. Display the Stack");
        puts("4. Peak Element");
        puts("0. Exit");
        puts("Enter your Choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: push(stack);
                    break;
            case 2: pop(stack);
                    break;
            case 3: display(stack);
                break;
            case 4: peak(stack);
                break;
        }
    }while(choice!=0);
}

struct Stack* createstack()
{
    int cap;
    struct Stack*stack=NULL;
    stack=(struct Stack*)malloc(sizeof(struct Stack));
   
    puts("Enter Capacity : ");
    scanf("%d",&cap);

    if(stack==NULL)
    {
        puts("Error in Memory Allocation");
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

void push(struct Stack* stack)
{   
    int data;

    puts("Enter Data");
    scanf("%d",&data);

    if(is_overflow(stack))
    {
        puts("Stack is Overflow");
        return;
    }
    else
    {
        stack->arr[++(stack->top)]= data;

    }
}

int is_overflow(struct Stack* stack)
{
    return stack->top == stack->capacity-1;
}

void display(struct Stack* stack)
{
    int i;
    if(is_underflow(stack))
    {
        puts("Stack is Underflow");
        return;
    }
    
    for(i = 0 ; i <= stack->top ; i++)
    {
        printf("%d=>",stack->arr[i]);

    }
    printf("\n");
}

void pop(struct Stack* stack)
{
    if(is_underflow(stack))
    {
        puts("Stack Underflow");
        return;
    }
    else
    {
        printf("Popped element is=%d\n",stack->arr[stack->top]);
        (stack->top)--;
    }
}

int is_underflow(struct Stack* stack)
{
    return stack->top==-1;
}

void peak(struct Stack* stack)
{
    
    if(is_underflow(stack))
    {
        puts("Stack Underflow");
        return;
    }
    else
    {
        printf("Peaked element is=%d\n",stack->arr[stack->top]);
        
    }
}

