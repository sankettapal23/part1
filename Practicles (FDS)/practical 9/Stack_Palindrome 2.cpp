#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class Stack
{
public:
char a[max];
int top ;
Stack(){
top=-1;
}
void push(char x){
   if(top == max-1){
       cout <<"Stack Overflow: ";
       return;
   }
   top++;
   a[top]=x;
}
char pop(){
   if(top == -1){
       cout <<"Stack underflow ";
       return -1;
}

return a[top--];

}

void display(){
   if(top ==-1){
       cout <<"Stack is Empty: ";
   }
   cout<<"stack is: ";
   for(int i=0; i<= top; i++){
       cout <<a[i] <<"";
   }
   cout<<endl;
}

};

int main(){
    Stack s;
    string input;

    char character;
    int flag = 1, i, j, mid, len;

    cout <<"Enter a String: ";
    getline(cin,input);
    string org_str="";
    for(int i=0; i< input.size(); i++){
        
        char ch =input[i];
       if ( ch >='a' and ch <='z'){
           ch = (char)(ch - 'a'+'A');
       }
       if (ch >= 'A' and ch <= 'Z' ){
          s.push(ch);
           org_str.push_back(ch);
           
       }
    }
    cout<<endl;
  s.display();
       
   cout <<"Reverse string is";
    while(s.top != -1){
        cout<<s.pop();
    }
    cout<< endl;
    
       len = org_str.size();
 
    mid = len / 2;

    for (i = 0; i < mid; i++)
        s.push(org_str[i]);

    if (len % 2 != 0)
        i++;

    while (org_str[i] != '\0')
    {

        character = s.pop();
        if (character != org_str[i])
            flag= 0;
        i++;
    }

    cout <<"Given String is "<<(flag ? "" : "Not ")<<"a Palindrome.";
}

/*
OUTPUT:
Enter a String: hiih
stack is: HIIH
Reverse string is HIIH
SLtack is Empty: stack is: 
Given String is a Palindrome.

*/