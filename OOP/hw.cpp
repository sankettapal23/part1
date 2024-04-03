#include<iostream>
using namespace std;
int main()
 {
   int numbers[10];
   int sum=0;
   cout<<"Enter 10 Numbers:";
   for(int i=0; i<10; ++i)
    {
        cout<<"Enter Numbers"<<i+1<<": ";
        cin>>numbers[i];
        if(numbers[i]>0)
         {sum+=numbers[i];}
    }
   cout<<"sum of Positive numbers:"<<sum;
   return(0);
 }