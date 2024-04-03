#include<iostream>
using namespace std;
class celcius
{   public:
    float cel;
    void read()
    {
        cout<<"Enter temp. in celcius=";
        cin>>cel;
    }
    void show()
    {
        cout<<"\nTemperature is %f celcius",cel;
    }
};
class farhen
{   public:
    float fa;
    void display()
    {
        cout<<"\n\nTemperature in farheneit ="<<fa;
    }
    farhen(celcius obj)
    {
        fa=(obj.cel*5/9)+32;
    }
};
int main()
{
    celcius c;
    farhen f(c);
    c.read();
    c.show();
    f=c;
    f.display();
    return 0;
}
