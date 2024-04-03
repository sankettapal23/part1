#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rollno;
    char name[50];
    char class[20];
    char div[10];
    int phone;
    struct student* next;
};

typedef struct student student;

void creatlinklist(struct student**);
struct student* createnode();
void displaylinklist(struct student*);
void ascending(struct student**);


int main()
{
    int choice;
    struct student* first_node=NULL;
    do
    {
        puts("1. create student data");
        puts("2. display student data");
        puts("3. Diaplay in ascending order by Roll no.");
        puts("0. Exit");

        puts("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:creatlinklist(&first_node);
                break;
            case 2:displaylinklist(first_node);
                break;
            case 3:ascending(&first_node);
                break;
            case 0:
                puts("Exit");  
        }
    }while(choice!=0);
    return (0);
}

void creatlinklist(struct student** head)
{
    struct student* new_node=NULL;
    struct student* tempnode=*head;
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

struct student* createnode()
{  
    int rollno;
    char name1[50];
    char class1[20];
    char div[10];
    int phone;
    student* newstudent=NULL;
    newstudent=(student*)malloc(sizeof(student));

    if(newstudent==NULL)
    {
        puts("Error in Memory Alloction");
        exit(EXIT_FAILURE);
    }
    else
    {
        puts("Enter Roll no");
        scanf("%d",&rollno);

        puts("Enter Name");
        scanf("%s",&name1);

        puts("Enter Class");
        scanf("%s",&class1);
        
        puts("Enter Division");
        scanf("%s",&div);

        puts("Enter Phone Number");
        scanf("%d",&phone);


        newstudent->rollno=rollno;
        strcpy(newstudent->name,name1);
        strcpy(newstudent->class,class1);
        strcpy(newstudent->div,div);
        newstudent->phone=phone;
        newstudent->next=NULL;
    }
        return newstudent;
    
}

void displaylinklist(struct student* head)
{
    if(head==NULL)
    {
    printf("NO DATA FOUND");
    }
    else
    {
        while (head != NULL) 
        {
            printf("Roll No: %d, Name: %s, Class: %s, Division: %s, Phone no:%d\n", head->rollno, head->name, head->class, head->div, head->phone);
            head = head->next;
        }
    }
    printf("\n\n");
}

void ascending(struct student** head)
{
    student* travnode1=*head;
    student* travnode2=(*head)->next;
    student* temp;
    temp=NULL;

    if((*head)==NULL)
    {
        return;
    }
    
    for(travnode1=(*head); travnode1!=NULL ; travnode1=travnode1->next)
      {  for(travnode2=travnode1->next ; travnode2!=NULL ; travnode2=travnode2->next)
        {
                if(travnode1->rollno > travnode2->rollno)
                {
                    temp->rollno=travnode1->rollno;
                    travnode1->rollno=travnode2->rollno;
                    travnode2->rollno=temp->rollno;        
                }
        }
      }
    printf("Linked List after sorting \n");
    displaylinklist(*head);
}