#include<graphics.h>
#include<iostream>
using namespace std;
int a[100],top=-1;
void push(int data)
{ 
  top++;
  a[top]=data;
 }
int pop()
{
 int x=a[top];
 top--;
 return x; 
 }

void display()
{ int k=0;
 char str[10];

int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
int j=300;

 while(k!=top+1)
 {
  delay(100);
rectangle(10,10+j,60,60+j);
delay(1000);
sprintf(str,"%d",a[k]);
outtextxy(20,25+j,str);
delay(1000);
j=j-50;
 
  k++;
 } 
 delay(10000);
closegraph();
cout<<endl;

 }
int main()
{ 
  int n,i,data;
  cout<<"How many elements you want to add :";cin>>n;
 for(i=0;i<n;i++)
 { 
  cout<<"Enter Top Element:";
  cin>>data;
  push(data); 
 
 }
 cout<<"How many You want to pop :";cin>>n;
 for(i=0;i<n;i++)
 { 
   pop(); 
 }
 cout<<"Operation performed\n";
 // cout<<"Top element of stack"<<pop()<<endl; 

  display();
 
}
