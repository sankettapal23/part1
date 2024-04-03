#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    node *head=NULL,*nn;
    nn= new node;
    nn->next=NULL;
    cout<<"Enter Data :";
    cin>>nn->data;
    
    if(head==NULL)
    {
        head=nn;
    }



    return(0);
}