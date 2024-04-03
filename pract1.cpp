#include<iostream>
#include<cstring>
using namespace std;
class Student
{
  int rno;
  char name[20];
  static int count;
  char clss[20];
  char div[10];
  int dob;
  char bg[4];
  char address[40];
  int tno[10];
  int dlno[10];
  
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
          cout<<"Enter the class ";
          cin>>clss;
          cout<<"Enter the Division ";
          cin>>div;
          cout<<"Enter Date of Birth ";
          cin>>dob;
          cout<<"Enter Blood Group ";
          cin>>bg;
          cout<<"Enter Address ";
          cin>>address;
          cout<<"Enter Telephone no. ";
          cin>>address;
          cout<<"Enter Driving license no. ";
          cin>>address;
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
    cout<<s.rno<<"\t"<<s.name<<"\t"<<s.clss<<"\t"<<s.div<<"\t       "<<s.dob<<"\t"<<s.bg<<"\t"<<s.address<<"\t"<<s.tno<<"\t"<<s.dlno<<"\n";  
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
   
   cout<<"\nR.NO\tName\tClass\tDivision\tDate of Birth\tBlood Group\tAddress\tTelephone no.\tDriving licence no\n\n";
   for(int i=0;i<n;i++)
   {
       display(*p[i]);
   }
   display(s1);
   display(s2);
   Student::showCount();
   return(0);
}

