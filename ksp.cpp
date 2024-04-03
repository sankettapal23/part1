#include<iostream>
using namespace std;
class complex
{
	int r=0,i=0;                
	public:
	/*void get()
	{cout<<"enter real part:";
	cin>>r;
	cout<<"Enter imaginary part:";
 	cin>>i;
	}*/
	complex operator +(complex c)
	{
	complex c3;
	c3.r=r + c.r;
	c3.i=i + c.i;
	return c3;
	}
	complex operator -(complex c)
	{
	complex c4;
	c4.r=r - c.r;
	c4.i = i -c.i;
	return c4;
	}

	/*void show()
	{
	cout<<r<<" + "<<i<<"i\n";
	}*/
friend istream& operator >>(istream& in,complex &c);
friend ostream& operator<<(ostream &out,complex &a);

};
istream& operator >>(istream &in,complex &c)
{
cout<<"enter real and img part";
in>>c.r>>c.i;
}
 ostream& operator<<(ostream &out,complex &a)
{
out<<a.r<<" + "<<a.i<<"i\n";
}
int main()
{
	complex c0,c1,c2,c3,c4;	
	//c1.get();
	//c2.get();
cin>>c1;
cin>>c2;
cout<<c1<<"\n"<<c2;
	c3 = c1 + c2;
	c4 = c1 - c2;
cout<<c3<<c4;

	//cout<<"0 + 0i\n";
	//c3.show();
	//c4.show();
	//c4.show();
	return 0;
}
// oopwplf eepef ll[
