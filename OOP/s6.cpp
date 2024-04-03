#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter A,B,C:-";
    cin>>a>>b>>c;
    if (a>b)
    {
        if(a>c)
        {
            cout<<"\n A is Greatest";
        }
        else
        {
            cout<<"\n C is Greatest";
        }
    }
    else
    {
        if(b>c)
        {
            cout<<"\n B is Greatest";
        }
        else
        {
            cout<<"\n C is Greatest";
        }
    }
    return(0);

}