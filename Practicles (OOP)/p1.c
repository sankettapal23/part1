#include<iostream>
#include<cstring>
using namespace std;
class Student
{
  int rno;
  char name[20];
  static int count;
  
  public:
       Student()
       {
           rno=10;
           strcpy(name,"abc");
           count++;
       }
       Student(Student &s)
       {
           rno=s.rno;
           strcpy(name,s.name);
           count++;
       }
       void getdata()
       {
          cout<<"Enter Roll No ";
          cin>>rno;
          cout<<"Enter Name ";
          cin>>name;
       }
       friend void display(Student &s);
       static void showCount()
       {
           cout<<"\n\nTotal Number of Student : "<<count;
       }
};
int Student::count=0;

void display(Student &s)
{
    cout<<s.rno<<"\t"<<s.name<<"\n";  
}
int main()
{
   Student s1; 
   s1.getdata();
   Student s2(s1);
   int n;
   cout<<"Enter total no of Student ";
   cin>>n;
   Student *p[n];
   
   for(int i=0;i<n;i++)
   {
       p[i]=new Student;
       p[i]->getdata();
   }
   
   cout<<"\nR.NO\tName\n\n";
   for(int i=0;i<n;i++)
   {
       display(*p[i]);
   }
   display(s1);
   display(s2);
   Student::showCount();
   return(0);
}

         

         
         
