#include<iostream>
# define max 10
using namespace std;
struct node
{
	long num;
	node* next;
};
class Hash
{
	node* arr[max];
	public:
	Hash()
	{
		for(int i=0;i<max;i++)
		arr[i]=NULL;
	}
	int hashFun(long int);
	void Insert();
	void Display();
};

int Hash::hashFun(long int n)
{
	return(n%10);
}
void Hash:: Insert()
{
	node* nn;
	nn= new node;
	cout<<"Please Enter the Number- "<<endl;
	cin>>nn->num;
	nn->next=NULL;
	int index=hashFun(nn->num);
	if (arr[index]==NULL)
	{
		arr[index]=nn;
	}
	else
	{
		node* temp=arr[index];
		while(temp->next!=NULL)
			temp=temp->next;
			temp->next=nn;
	}
}

void Hash::Display()
{
	for(int i=0;i<max;i++)
	{
		node* temp=arr[i];
		if(temp==NULL)
			cout<<i<<"------>NULL"<<endl;
		else
		{
			if(temp->next==NULL)
				cout<<i<<"----->"<<temp->num<<endl;
			else
			{
				cout<<i<<"------>";
				while(temp->next!=NULL)
				{
					cout<<temp->num<<" --> ";
					temp=temp->next;
				}
				cout<<temp->num<<endl;
			}
		}
	}
}

int main()
{
	int choice;
	Hash h;
	do
	{	
		cout<<"1.Insert\n2.Display\n0.Exit\n";
		cout<<"Plese Enter Your Choice"<<endl;
		
		cin>>choice;

		switch(choice)
		{
			case 1:h.Insert();
				break;
			case 2:h.Display();
				break;
		}
	}while(choice!=0);
	
	return 0;
}