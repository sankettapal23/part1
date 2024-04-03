#include<iostream>
using namespace std;
#define MAX 10
struct node
{
    int vertex;
    struct node* next;
};
class graph
{
    int visited_1[MAX],visited_2[MAX];
    struct node* head[MAX];
    struct node* temp;
    struct node* front ,*rear;
    int count;
    public:
        graph();
        void create();
        void show();
        void dfs(int);
        void bfs(int);
        void enqueue(int);
        int dequeue();
        bool isEmpty();
};
graph:: graph()
{
    int i;
    for(i=0 ; i<MAX ; i++)
        head[i] =NULL;
    for(i=0 ; i<MAX ;i++)
    {
        visited_1[i] = 0;
        visited_2[i]=0;
    }
    front=NULL;
    rear=NULL;
}
void graph :: create()
{
    int v1 , v2,i;
    char ch;
    struct node* N ;
    cout<<"\nenter total number of nodes :";
    cin>>count;
    for(i=0;i<count;i++)    
    {                        
        N=new node;         
        N->vertex=i;        
        N->next=NULL;       
        head[i]=N;   
    }
    do{
        cout<<"\nEnter Vertex pair having connection (vertex no. starts from Zero):";
        cin>>v1>>v2;
        if(v1>=count || v2>=count)
            cout<<"\nInvalid Pair"<<endl;
        else
        {
           
            N=new node;
            N->vertex=v2;
            N->next =NULL;
            temp =head[v1];
            while(temp->next!=NULL)
                temp =temp->next;
            temp->next =N;
           
            N=new node;
            N->vertex= v1;
            N->next=NULL;
            temp =head[v2];
            while(temp->next!=NULL)
                temp =temp->next;
            temp->next=N;
        }
        cout<<"\nDo you want to add Pair :(y/n)"<<endl;
        cin>>ch;

    }while(ch == 'y');

    
}

void graph :: show()
{
    int i;
    cout<<"\nCount of Nodes = "<<count<<endl;
    for(i=0; i<count;i++)
    {
        temp = head[i];
        while(temp->next!=NULL)
        {
            cout<<temp->vertex<<"-->";
            temp=temp->next;
        } 
        cout<<temp->vertex<<"-->NULL"<<endl;
    }
}

void graph :: dfs(int v)
{
    int i,flag;
    temp = head[v];
    cout<<temp->vertex<<"--->";
    visited_1[v]=1;
    while(temp!=NULL)
    {
        if(visited_1[temp->vertex]==0)
            dfs(temp->vertex);
        else
            temp =temp->next;
    }
}



void graph :: bfs(int start)
{
    struct node* ptr;

    enqueue(start);
    visited_2[start] = 1;

    while (!isEmpty())
    {
        int v = dequeue();
        cout << v << "--->";

        temp = head[v];
        ptr = temp;

        while (temp != NULL)
        {
            if (visited_2[temp->vertex] == 0)
            {
                enqueue(temp->vertex);
                visited_2[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}



void graph :: enqueue(int q)
{
    struct node* nn = new node;
    nn->vertex=q;
    nn->next=NULL;
    if(isEmpty())
        front = rear = nn;
    else
    {
        rear->next=nn;
        rear=nn;
    }
}

bool graph :: isEmpty()
{
    return front==NULL;
}

int graph ::dequeue()
{
    int val;
    if(isEmpty())
        cout<<"\nEmpty queue, nothing to remove"<<endl;
    else
    {
        struct node* temp=front;
        val=temp->vertex;
        if(front==rear)
            front =rear =NULL;
        else
            front=front->next;
        delete(temp);
        
    }
    return val;
}
int main()
{
    int num_node;
    graph obj;
    obj.create();
    obj.show();
    cout<<"\nEnter node number From where you want to traverse DFS :";
    cin>>num_node;
    cout<<"\nTree Traversal using DFS :"<<endl;
    obj.dfs(num_node);
    cout<<"NULL"<<endl;
    cout<<"\nEnter node number from where to travverse by BFS :";
    cin>>num_node;
    cout<<"\nTree Traversal using BFS :"<<endl;
    obj.bfs(num_node);
    cout<<"NULL"<<endl;

    return 0;
}