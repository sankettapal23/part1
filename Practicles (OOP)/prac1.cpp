#include<iostream>
using namespace std;

class complex
{
    int real,imag;
    public:
        complex()
        {
            int real=0;
            int imag=0;
        }
    
    friend istream& operator>>(istream &in, complex &b);
    friend ostream& operator<<(ostream &out, complex  const &b);

    complex operator +(complex const &b)
    {
        complex res;
        b3.real=real+b2.real;
        b3.imag=imag+b2.imag;
        return(b3);
    }

    complex operator* (complex b2)
    {
        complex b3;
        b3.real=(real.b2.real)-(imag*b2.imag);
        b3.imag=(real*b2.imag)+(imag+b2.real);
        return(b3);
    }
};
istream& operator >>(istream &in,complex &c)
{
cout<<"enter real and img part";
in>>c.real>>c.imag;
}
 ostream& operator<<(ostream &out,complex &c)
{
out<<c.real<<" + "<<c.imag<<"i\n";
}
int main()
{
    complex c1,c2,c3,c4;
    cout<<"Enter first Real & imaginary no. "<<endl;
    cin>>c1;
    cout<<"Enter Second Real & Imaginary No. "<<endl;
    cin>>c2;

    c3=c1+c2;
    cout<<"Complex no 1 =";
    cout<<c1;
    cout<<"Complex no 2= ";
    cout<<c2;
    cout<<"Addition = ";
    cout<<c3;

    c4=c1*c2;

    cout<<"Multiplicatioon = ";
    cout<<c4;
    return (0);
}