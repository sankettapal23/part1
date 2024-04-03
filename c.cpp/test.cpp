34#include<iostream>
using namespace std;
class celcius
{
    public:
    float cel;
    void read()
    {
        cout<<"Enter tempeerature in celcius =";
        cin>>cel;
    }
    void show()
    {
        cout<<"\nTemperature is"<<cel<<" celcius";
    }
};
class farheneit
{
    public:
    float fa;
    void display()
    {
        cout<<"\n\nTemperature in Farheneit is ="<<fa<<" F";
    }
    farheneit(celcius ob)
    {
        fa=(ob.cel*5/9)+32;
    }
};
int main()
{
    celcius c;
    farheneit f(c);
    c.read();
    c.show();
    f=c;
    f.display();
    return 0;

}