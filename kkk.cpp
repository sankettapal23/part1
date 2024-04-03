#include<iostream>
using namespace std;
class complex
{
	int r,i;
	public:
		complex operator +(complex c)
		{complex c3;
		c3.r = c.r + r;
		c3.i= c.i + i;
		return c3;
    		}
friend istream& operator >>(istream& in, complex &c);
friend ostream& operator <<(ostream& out, complex &d);
};
istream& operator >>(istream& in, complex &c)
{
 cout<<"Enter real and imaginary part\n";
 in>>c.r>>c.i;
 }
ostream& operator <<(ostream& out, complex &d)
{
 out<<d.r<<" + "<<d.i<<"i\n";
}
int main()
{
	complex c1,c2,c3;
	cin>>c1;
	cin>>c2;
	c3= c1+c2;
 	cout<<c1;
	cout<<c2;
	cout<<c3;
	return 0;
}		
		
