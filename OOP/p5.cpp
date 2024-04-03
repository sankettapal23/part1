#include<iostream>
#include<cstring>
using namespace std;
struct student
 {
  int r;
  char name[10];
  float p;
  };
int main()
{
 struct student s1;
 s1.r=10;
 strcpy(s1.name,"abc");
 s1.p=78.32;
 cout<<"\n Roll no-"<<s1.r;
 cout<<"\n Name-"<<s1.name;
 cout<<"\n Percentage"<<s1.p;
 return(0);
}  
