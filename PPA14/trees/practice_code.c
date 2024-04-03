#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};
struct Queuenode
{
    struct node* nodedata;
    struct Queuenode* next;
};
struct Queue
{
    struct Queuenode* front;
    struct Queuenode* rear;
};

struct node* built_tree();
struct node* create_node(int);
void level_order_traversal(struct node*);
struct Queue* create_queue();
void enqueue(struct Queue*,struct node*);
struct Queuenode*create_qnode(struct node* );
int is_empty(struct Queue* );
struct node* dequeue(struct Queue* );


void main()
{
    struct node* root=NULL;
    root=built_tree();
    printf("Level order tarversal\n");
    level_order_traversal(root);

}

struct node* built_tree()
{
    struct node* root=NULL;
    int data;
    puts("Enter a data");
    scanf("%d",&data);
    if(data == -1)
    {
        return NULL;
    }
    root=create_node(data);
    printf("Enter a data for left of %d node\n",data);
    root->left=built_tree();

    printf("Enter a data for right of %d node\n",data);
    root->right=built_tree();

    return root;
}
struct node* create_node(int data)
{
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->left=NULL;
    newnode ->data=data;
    newnode->right=NULL;

    return newnode;
}

void level_order_traversal(struct node* root)
{
    struct Queue* queue=NULL;
    struct node* tempnode=NULL;
    queue=create_queue();

    enqueue(queue,root);

    while(!is_empty(queue))
    {
        tempnode=dequeue(queue);
        printf("%d =>",tempnode->data);

        if(tempnode -> left != NULL)
            enqueue(queue,tempnode->left);
        if(tempnode->right != NULL)
            enqueue(queue,tempnode->right);
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
    queue->front=NULL;
    queue->rear=NULL;

    return queue;
}

void enqueue(struct Queue* queue,struct node* root)
{
    struct Queuenode* qnode=NULL;
    qnode=create_qnode(root);

    if(queue->front ==NULL)
    {
        queue -> front = queue -> rear = qnode;
    }
    else
    {
    queue -> rear -> next = qnode;
    queue -> rear = queue -> rear -> next;
    }
}

struct Queuenode*create_qnode(struct node* root)
{ 
    struct Queuenode* qnode=NULL;
    qnode=(struct Queuenode*)malloc(sizeof(struct Queuenode));
    if(qnode==NULL)
    {
        return NULL;
    }
    qnode -> nodedata = root;
    qnode -> next = NULL;

    return qnode;
}

int is_empty(struct Queue* queue)
{
    return queue->front == NULL;
}

struct node* dequeue(struct Queue* queue)
{
    if(is_empty(queue))
    {
        return NULL;
    }
    struct Queuenode* tempnode=NULL;
    struct node* tempdata=NULL;
    tempnode=queue->front;
    tempdata=queue->front->nodedata;

    queue->front=queue->front->next;
    if(queue->front==NULL)
    {
        queue->rear=NULL;
    }

    free(tempnode);

    return(tempdata);
}