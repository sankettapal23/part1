#include<iostream>
using namespace std;
class test
{   int n;
    public:
    test()
    {
        cout<<"enter number =";
        cin>>n;        
    }
    friend int getsum(test t);
    };
int getsum(test t)
{
    int sum=0;
    while(t.n!=0)
    {
        sum=sum+(t.n%10);
        t.n=t.n/10;
    }
    return(sum);
}
int main()
{   int show;
    test t;
    show=getsum(t);
    cout<<"Sum of the digits ="<<show;
    return 0;
}