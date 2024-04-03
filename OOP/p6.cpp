#include<iostream>
#include<string>
using namespace std;
union student
 {
 int r;
 char name[10];
 float p;
 };
int main()
{
union student s1;
cout<<"\n Enter Roll no,Name & percentage";
cin>>s1.r>>s1.name>>s1.p;
cout<<"\n Name -"<<s1.name;
cout<<"\n Roll no.1"<<s1.r;
cout<<"\n Percentage"<<s1.p;
return(0);
} 
