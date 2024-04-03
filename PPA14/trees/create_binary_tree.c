#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* built_tree();
struct node* createnode(int);
void display(struct node* );


void main()
{
    struct node* root=NULL;
    root=built_tree();
    puts("Given Tree is :");
    display(root);
}

struct node* built_tree()
{
    int data;
    struct node* root=NULL;
    puts("Enter a data");
    scanf("%d",&data);

    if(data == -1)
        return NULL;

    root= createnode(data);

    printf("Enter a data for left of %d node\n",data);
        root->left = built_tree();
    
     printf("Enter a data for right of %d node\n",data);
        root->right = built_tree();
    
    return root;
}

struct node* createnode(int data)
{
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void display(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d=>",root->data);
    display(root->left);
    display(root->right);   
}
