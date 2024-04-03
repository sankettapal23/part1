#include<iostream>
using namespace std;
class Queue
{
public:
int q[5];
int no;
int front,rear;
Queue()
{
front=rear=0;
}
void insert();
void delete1();
void display();
int isfull();
int isempty();
};
void Queue::insert()
{
if(isfull())
{
cout<<"Queue is full\n";
}
else
{
cout<<"Enter number\n";
cin>>no;
q[rear]=no;
rear++;
}
}
void Queue::delete1()
{
if(isempty())
{
cout<<"Queue is empty\n";
}
else
{
no=q[front];
cout<<"Element is"<<no<<endl;
front++;
}
}
void Queue::display()
{
int i;
int temp=front;
if(front==rear)
{
cout<<"Queue empty\n";
}
else
{
for(i=temp;i<rear;i++)
{
cout<<q[i];
}
}
}
int Queue:: isfull()
{
if(front==0 && rear==5)
	return 1;
else
	return 0;
}
int Queue::isempty()
{
if(front==rear)
	return 1;
else
	return 0;
}
int main()
{
int ch;
Queue q;
while(ch!=4)
{
cout<<"Enter choice\n";
cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit\n";
cin>>ch;
switch(ch)
{
case 1:q.insert();
	break;
case 2:q.delete1();
	break;
case 3:q.display();
	break;
case 4:break;
default:cout<<"Wrong choice\n";
	break;
}
}
}





