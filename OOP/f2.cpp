#include<iostream>
using namespace std;
namespace abc
{
    int a=10;
}
namespace other
{
    int a=20;
    void display()
    {
        cout<<"\n Other a="<<a;
    }
}
int main()
{
    int a=30;
    cout<<"\n In abc a="<<abc::a;
    other::display();
    cout<<"\n in main a="<<a;
    return(0);
}