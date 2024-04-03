#include <iostream>
using namespace std;
struct node
{
int rno;
struct node *next;
};
class SEA
{
public:
struct node * insert();
int display(struct node *);
void intersect(struct node * , struct node *);
void unio(struct node * , struct node *);
void diff1(struct node * , struct node *);
void diff2(struct node * , struct node *);
};
struct node * SEA:: insert()
{
int n,i;
node *temp,*nn,*start;
start=NULL;
cout<<"How Many Students?";
cin>>n;
for(i=0;i<n;i++)
{
nn=new node;
cout<<"Enter roll no. of students:";
cin>>nn->rno;
nn->next=NULL;
if(start==NULL)
{
start = nn;
}
else
{
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=nn;
}
}
return(start);
}
int SEA::display(struct node *t)
{
int count=0;
node *temp = t;
while(temp!=NULL)
{
cout<<temp->rno<<"\t";
temp=temp->next;
count++;
}
cout<<"\nTotal no. of students= "<<count<<"\n";
return (count);
}
void SEA::intersect(struct node *p , struct node *q)
{
while(p!=NULL)
{
int found=0;
node *temp=q;
while(temp!=NULL)
{
if(p->rno==temp->rno)
{
found=1;
}
temp=temp->next;
}
if(found==1)
{
cout<<p->rno<<"\t";
}
p=p->next;
}
}
void SEA::unio(struct node *p , struct node *q)
{
    //
    node *temp=p;
while (temp!=NULL)
{
cout<<temp->rno<<"\t";
temp=temp->next;
}
for (q ; q!=NULL ; q=q->next)
{
int found=0;

for (temp=p ; temp!=NULL ; temp=temp->next)
{
if(q->rno == temp->rno)
{
found=1;
}
}
if (found ==0)
{
cout<<q->rno<<"\t";
}
}
}
void SEA::diff1(struct node *p , struct node *q)
{
while(p!=NULL)
{
int found=0;
node *temp=q;
while(temp!=NULL)
{
if(p->rno==temp->rno)
{
found=1;
}
temp=temp->next;
}
if(found==0)
{
cout<<p->rno<<"\t";
}
p=p->next;
}
}
void SEA::diff2(struct node *p , struct node *q)
{
for(q ; q!=NULL ; q=q->next)
{
int found=0;
node *temp=p;
for(temp ; temp!=NULL ;temp=temp->next)
{
if(q->rno==temp->rno)
{
found=1;
}
}
if(found==0)
{
cout<<q->rno<<"\t";
}
}
}
int main()
{
struct node *head=NULL,*head1=NULL;
SEA a;
char x;
int choice,m,van,bat,total;
cout<<"How Many Total Students in class?";
cin>>m;
do
{
cout<<" \n1.Insert\n 2.Display\n 3.Students Who Like Both\n 4.Students Who like either Vanilla or Butterscotch\n 5.Students Who like only Vanilla\n 6.Students who like only Butterscotch\n 7.Students who not like neither Vanilla nor Butterscotch\n";
cout<<"Enter choice: ";
cin>>choice;
switch(choice)
{
case 1: cout<<"Students Like Vanilla: ";
head=a.insert();
cout<<"Students Like Butterscotch: ";
head1=a.insert();
break;
case 2:
cout<<"Student who like vanilla: \n";
van=a.display(head);
cout<<"Student who like butterscotch: \n";
bat=a.display(head1);
break;
case 3:
cout<<"Students Who Like Both"<<endl;
a.intersect(head , head1);
break;
case 4:
cout<<"Students Who like either Vanilla or Butterscotch"<<endl;
a.unio(head , head1);
break;
case 5:
cout<<"Students Who like only Vanilla"<<endl;
a.diff1(head , head1);
break;
case 6:
cout<<"Students who like only Butterscotch"<<endl;
a.diff2(head , head1);
break;
case 7:
van=a.display(head);
bat=a.display(head1);
total=m-van-bat;
cout<<"Students who not like neither Vanilla nor Butterscotch\n"<<total<<endl;
break; 
}
cout<<"\ndo you want to continue(y/n): ";
cin>>x;
} while(x=='y');
return 0;
}
