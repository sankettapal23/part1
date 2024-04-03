#include<iostream>
using namespace std;

struct node
{
	struct node* left;
	struct node* right;
	int data;
};

node* createnode(int value)
{
	node* newnode=new node();
	newnode->left=NULL;
	newnode->data=value;
	
	return newnode;
}

node* insert(node* root , int value)
{
	node* newnode;

	if(root==NULL)
	{
		return createnode(value);
	}
	
	if(value < root->data)
	{
		root->left=insert(root->left,value);
	}
	else
	{
		root->right=insert(root->right,value);
	}

	return root;
}

int height(node* root)
{
	if((root==NULL)||(root->left==NULL && root->right==NULL))
	{
		return 0;
	}
	
	int leftheight= height(root->left);
	int rightheight=height(root->right);

	return max(leftheight,rightheight)+1;
}


int minvalue(node* root)
{
	if(root==NULL)
	{
		cout<<"Tree is Empty";		
		return 0;
	}
	while(root->left !=NULL)
	{
		root=root->left;
	}
	return(root->data);
}

void swaprole(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	node* temp=root->left;
	root->left=root->right;
	root->right = temp;

	swaprole(root->left);
	swaprole(root->right);
}

bool search(node* root, int value)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty";
		return false;
	}
	else
	{
		
		if(root->data ==value)
		{
			return true;
		}
		else if(value < root->data)
		{
			return search(root->left, value);
		}
		else
		{
			return search(root->right, value);
		}
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

int main()
{
	node* root= NULL;
	int choice;
	int longestpath,minval,searchvalue,value;
	do
	{
		cout<<"\n1.Insert Value \n2.Nodes in Longest Path \n3.Minimum value \n4.Swap Left and Right Nodes \n5.Search Value\n6. Display\n0.Exit\n";
		cout<<"\nEnter Your choice \n";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"Enter The value ";
				cin>>value;
				root=insert(root,value);
				break;
			case 2: longestpath=height(root);
				cout<<"Number of nodes in Longest path from root "<<longestpath<<endl;
				break;
			case 3: minval=minvalue(root);
				cout<<"Minimun value is "<<minval<<endl;
				break;
			case 4:swaprole(root);
				break;
			case 5: cout<<"Enter the value want to search ";
				cin>>searchvalue;
				if(search(root,searchvalue))
				{
					cout<<"Value Found in Tree\n";
				}
				else
				{
					cout<<"\nValue Not found in Tree\n";
				}
				break;
			case 6:
				inorder(root);
				break;
			
			case 0: 
				cout<<"Exit\n";
		}
	}while(choice!=0);
}