#include<iostream>
using namespace std;
class stack
{
  int top;
  char a[40];
  public:
  stack()
  {
     top=-1;
     
  }
  void push(char b)
  {
    top++;
    a[top]=b;
  }
  void pop(char x)
  {
   if(x==')'&&a[top]=='(')
    top--;
   else if(x==']'&&a[top]=='[')
    top--;
   else if(x=='}'&&a[top]=='{')
    top--;
      else
    {
       cout<<"\nexpression is not well paranthesis";
       exit(0);
    }
    
  }
  int check()
  {
    if(top==-1)
    {
      return 1;
    }
    else
    {
       return 0;
    }
  }
};
int main()
{
   char eq[30];
   int i;
   stack s;
   cout<<"\nEnter the expression";
   cin>>eq;
   for(i=0;eq[i]!='\0';i++)
   {
     if(eq[i]=='(' || eq[i]=='[' || eq[i]=='{')
     {
        s.push(eq[i]);
       
        
     }
     if(eq[i]==')' || eq[i]==']' || eq[i]=='}')
     {
       s.pop(eq[i]);
   
     }
   }
    int c=s.check();
    if(c==1)
    {
       cout<<"\nexpression is well paranthasis";
    }
    else
    {
       cout<<"\nexpression is not well paranthesis";
    }
}
    
