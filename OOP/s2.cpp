#include<iostream>
#include<string.h>
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
 cout<<"\n Enter roll no , name, percent";
 cin>>s1.r>>s1.name>>s1.p;
 cout<<"\n Roll no.1"<<s1.r;
 cout<<"\n Name is :"<<s1.name;
 cout<<"\n Percentage :-"<<s1.p;
 return (0);
}