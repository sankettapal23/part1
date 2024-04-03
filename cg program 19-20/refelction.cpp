#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{ // Accepting input
int a[100],a1[100],n,b,c,rx,ry,a3[100];
n=n+1;
double z;
cout<<"enter v points";
cin>>n;

int p=n*2;
for(int i=0;i<p;i++)
{
cout<<"enter coordinates";
cin>>a[i];			// accepting coordinates
}
a[p]=a[0];
a[p+1]=a[1];	// closing polygon
n=n+1;
cout<<"enter rotation point";
cin>>rx>>ry;
cout<<"enter angle";
cin>>z;
z=z*3.14/180;

int gd=DETECT, gm=VGAMAX;
               initgraph(&gd, &gm, 0);
	rectangle(100,100,400,400);
	line(250,100,250,400);
	line(100,250,400,250);
drawpoly(n,a);
			delay(10000); 
setcolor(2);
 for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a1[i]=a[i];		
}
else
{
if(a[i]<250)
{
b=250-a[i];
a1[i]=b+250;
}
else
{
b=a[i]-250;
a1[i]=250-b;
}
}
} 
a1[p]=a1[0];
a1[p+1]=a1[1];

drawpoly(n,a1);
			delay(10000);  
//////////////////////////////
setcolor(2);
 for(int i=0;i<p;i++)
{
	if(i%2!=0)
{
	a1[i]=a[i];		
}
else
{
if(a[i]<250)
{
b=250-a[i];
a1[i]=b+250;
}
else
{
b=a[i]-250;
a1[i]=250-b;
}
}
} 
a1[p]=a1[0];
a1[p+1]=a1[1];

drawpoly(n,a1);
			delay(10000);  
//////////////////////////////////////////////
cleardevice();
rectangle(100,100,400,400);
	line(250,100,250,400);
	line(100,250,400,250);
line(100,100,400,400);
//drawpoly(n,a);
setcolor(5);
drawpoly(n,a);
setcolor(6);
 for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a1[i]=a[i+1];		
}
else
{
a1[i]=a[i-1];
}
} 
a1[p]=a1[0];
a1[p+1]=a1[1];

drawpoly(n,a1);
delay(10000);
//////////////////////////////////
cleardevice();
drawpoly(n,a);
////////////////////////////////////////
setcolor(RED);
for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a1[i]=a[i]-rx;		
}
else
{
a1[i]=a[i]-ry;
}
} 
a1[p]=a1[0];
a1[p+1]=a1[1];
drawpoly(n,a1);
delay(10000);
////**********************//////////////////////
setcolor(BLUE);
for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a3[i]=a1[i]*cos(z)-a1[i+1]*sin(z);
}
else
a3[i]=a1[i-1]*sin(z)+a1[i]*cos(z);
} 
a3[p]=a3[0];
a3[p+1]=a3[1];
drawpoly(n,a3);
delay(10000);
////////////////////////////////////////////////
setcolor(CYAN);
for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a1[i]=a3[i]+rx;		
}
else
{
a1[i]=a3[i]+ry;
}
} 
a1[p]=a1[0];
a1[p+1]=a1[1];

drawpoly(n,a1);
delay(100000);
////////////////////////////////////////
closegraph();
}




/*output
enter v points4
enter coordinates150
enter coordinates120
enter coordinates200
enter coordinates120
enter coordinates200
enter coordinates180
enter coordinates150
enter coordinates180
enter rotation point100
100
enter angle20
*/
