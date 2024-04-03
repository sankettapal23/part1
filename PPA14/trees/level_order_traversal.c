#include<stdio.h>
#include<stdlib.h>

struct Queuenode
{
    struct node* node_data;
    struct Queuenode* next;
};
struct Queue
{
    struct Queuenode* front;
    struct Queuenode* rear;
};
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* built_tree();
struct node* createnode(int);
void display(struct node* );
void level_order_traversal(struct node*);
struct Queue* create_queue();
void enqueue(struct Queue* , struct node* );
struct Queuenode* create_Queuenode(struct node*);
int is_empty(struct Queue*);
struct node* dequeue(struct Queue* );


void main()
{
    struct node* root=NULL;
    root=built_tree();
    puts("Given Tree is :");
    display(root);
    printf("\n");
    puts("Level order Traversal is :");
    level_order_traversal(root);
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
void level_order_traversal(struct node* root)
{
    struct Queue* queue=NULL;
    queue=create_queue();
    enqueue(queue,root);
    struct node* tempdata=NULL;

    while( ! is_empty(queue))
    {
        tempdata=dequeue(queue);
        printf("%d=>",tempdata->data);
        if(tempdata->left != NULL)
        {
            enqueue(queue,tempdata->left);
        }
        if(tempdata->right != NULL)
        {
            enqueue(queue,tempdata->right);
        }

    }
}

struct Queue* create_queue()
{
    struct Queue* queue=NULL;
    queue=(struct Queue*)malloc(sizeof(struct Queue));
    if(queue==NULL)
    {
        return NULL;
    }
    queue -> front = NULL;
    queue -> rear = NULL;
    
    return queue;
}

void enqueue(struct Queue* queue, struct node* root)
{
    struct Queuenode* q_node=NULL;
    q_node=create_Queuenode(root);
    if(queue -> front == NULL)
    {
        queue->front = queue->rear = q_node;
    }
    else
    {
        queue->rear->next = q_node;
        queue->rear = queue->rear->next;
    }
}

struct Queuenode* create_Queuenode(struct node* root)
{
    struct Queuenode* new_qnode=NULL;
    new_qnode=(struct Queuenode*)malloc(sizeof(struct Queuenode));

    if(new_qnode == NULL)
    {
        return NULL;
    }

    new_qnode -> next = NULL;
    new_qnode -> node_data = root;

    return new_qnode;
}

int is_empty(struct Queue*queue)
{
    return queue->front == NULL;
}

struct node* dequeue(struct Queue* queue)
{
    struct node* tempdata=NULL;
    struct Queuenode* tempnode=NULL;
    tempdata = queue->front->node_data;
    tempnode = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL)
    {
        queue->rear=NULL;
    }

    free(tempnode);
    return(tempdata);
}