#include<iostream>
using namespace std;
class pizza
{
int order[10];
int max=5;
int f,r;
public :
pizza(){
f=-1,r=-1;
}
int full(){
    if(((f==0)&&(r==(max-1)))||(f==(r+1)%max))
        return 1;
    else
        return 0;
}
int qempty(){
    if(f==-1)
        return 1;
    else
        return 0;
}
void add(int a){
if(full()){
cout<<"\n ORDER IS FULL!!!";
}
else{
if(f==-1){
f=r=0;
}
else{
r=(r+1)%max;
}
order[r]=a;
}
}
void remove(){
int i;
i=order[f];
    if(f==r){
        f=r=-1;
        }
    else{
        f=(f+1)%max;
        }
cout<<"\n ORDER DELETED : "<<i;
}
void display(){
int temp;
temp=f;
if(qempty())
{
    cout<<"\nCURRENTLY NO ORDER\n";
}
else{
    cout<<"\nTHE ORDER ARE : \n\n";
while(temp!=r){
    cout<<" "<<order[temp];
    temp=(temp+1)%max;
}
cout<<" "<<order[temp];
}}
};
int main(){
int ch;
pizza p;
do
{
cout<<"\n\n ************** PRACTICAL NO-15(E-32) PIZZA PARLOUR**************";
cout<<"\n1. ORDER \n2. REMOVE ORDER \n3.DISPLAY ORDER \n4. EXIT";
cout<< "\nENTER YOUR CHOICE :";
cin>>ch;

switch(ch)
{
case 1: int o;
        cout<<"\nEnter Order number : ";
        cin>>o;
        p.add(o);
        break;

case 2: p.remove();
        break;

case 3: p.display();
        break;
}

}while(ch!=4);
return 0;
}