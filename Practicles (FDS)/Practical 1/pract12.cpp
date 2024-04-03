#include<iostream>
#include<cstring>
using namespace std;
class stackin
{
int top,size;
char st[20],exp[20];
public:
void push(char);
char pop();
void inpost();
int precedence(char);
};
void stackin::inpost()
{
cout<<"\nENTER THE INFIX EXPRESSION : \n";
cin>>exp; 
top=-1;
char post[20]; 
int k=0;
char ch;
for(int i=0;exp[i]!='\0';i++) 
{
if(isalpha(exp[i])||isdigit(exp[i]))
{
post[k]=exp[i]; 
k++;
}
else if(exp[i]=='(')
{
push('(');
}
else if(exp[i]==')')
{
while((ch=pop())!='(')
{
    post[k]=ch;
    k++;
}
}
else
{

while(precedence(st[top])>=precedence(exp[i]))
{
post[k]=pop();
k++;
}
push(exp[i]);
}
}
while(top>=0)
{
post[k]=pop();
k++;
}
post[k]='\0';
cout<<"\nTHE POSTFIX EXPRESSION IS : \n"<<post<<"\n";
}
void stackin::push(char ch)
{
top++;
st[top]=ch;
}
char stackin::pop()
{
char ch;
ch=st[top];
top--;
return ch;
}
int stackin::precedence(char c)
{
if(c=='('||c==')')
return(0);
if(c=='+'||c=='-')
return(1);
if(c=='*'||c=='/')
return(2);
}
int main()
{
stackin s1; 
int x;
char c;
do
{
cout<<"\n*******************PRACTICAL NO-12(D27)**********************";
cout<<"\n1. INFIX TO POSTFIX";
cout<<"\n2. EXIT.\n";
cout<<"\n ENTER YOUR CHOICE : ";
cin>>x;
switch(x)
{
case 1:
        s1.inpost();
        break;
case 2:
        break;
}


cout<<"\nDo you wish to continue? (y/n) : ";
cin>>c;
}
while(c=='y');
return 0;
}