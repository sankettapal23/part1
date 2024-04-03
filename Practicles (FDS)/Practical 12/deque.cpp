#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class dQ
{
	struct node *front,*rear;
	public:
		dQ()
		{
			front=rear='\0';
		}
		void enfront();
		void enrear();
		void defront();
		void derear();
		void display();
};

void dQ::enfront()
{
	node*nn;
	nn=new node;
	cout<<"Enter the element - ";
	cin>>nn->data;
	nn->next=NULL;
	
	if(rear==NULL)
		front=rear=nn;
	else{
		nn->next=front;
		front=nn;
	}
}

void dQ::enrear()
{
	node*nn;
	nn=new node;
	cout<<"Enter the element - ";
	cin>>nn->data;
	nn->next=NULL;
	
	if(front==NULL)
		front=rear=nn;
	else{
		rear->next=nn;
		rear=nn;
	}
}

void dQ::defront()
{
	if(front==NULL)
		cout<<"Underflow";
	else{
		node *temp;
		temp=front;
		front=front->next;
		delete(temp);
	}
}

void dQ::derear()
{
	node *temp,*d;
	temp=front;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	d=rear;
	temp->next=NULL;
	rear=temp;
	delete(d);
}

void dQ::display()
{
	node *temp;
	temp=front;
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	dQ d;
	d.enrear();
	d.enrear();
	d.enfront();
	d.enrear();
	d.enfront();
	d.enfront();
	d.display();
	cout<<"\n";
	d.derear();
	d.defront();
	d.display();
	cout<<"\n";
	return 0;
}
