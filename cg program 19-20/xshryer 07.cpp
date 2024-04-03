#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{ 
int n,tx,ty,sx,sy,b,c, a[100],a1[100],a2[100],a3[100],a4[100],a5[100];

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
double z;
cout<<"enter tx,ty";
cin>>tx>>ty;

cout<<"enter sx,sy";
cin>>sx>>sy;
cout<<"enter angle";
cin>>z;
cout<<"enter x shear factor";
cin>>b;
cout<<"enter y shear factor";
cin>>c;
z=z*3.14/180;

 int gd=DETECT, gm=VGAMAX;
               initgraph(&gd, &gm, 0);
	outtextxy(320,100,"ORIGINAL OBJECT");
              drawpoly(n,a);
			delay(1000); 
cleardevice();

 setcolor(2);
 for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a1[i]=a[i]+tx;		//translation 
}
else
a1[i]=a[i]+ty;
} 
a1[p]=a1[0];
a1[p+1]=a1[1];
outtextxy(320,200,"TRANSLATION");
drawpoly(n,a1);
			delay(1000);  
cleardevice(); 

setcolor(3);
for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a2[i]=a[i]*sx;		// scaling
}
else
a2[i]=a[i]*sy;
} 
a2[p]=a2[0];
a2[p+1]=a2[1];
outtextxy(320,200,"SCALING");
drawpoly(n,a2);
			delay(1000);

cleardevice();

setcolor(4);
for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a3[i]=a[i]*cos(z)-a[i+1]*sin(z);
}
else
a3[i]=a[i-1]*sin(z)+a[i]*cos(z);
} 
a3[p]=a3[0];
a3[p+1]=a3[1];
outtextxy(320,200,"ROTATION"); //rotation
drawpoly(n,a3);
			delay(1000);  
cleardevice();

setcolor(5);
 for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a4[i]=a[i]+b*a[i+1];
}
else
a4[i]=a[i];
}
a4[p]=a4[0];
a4[p+1]=a4[1];
outtextxy(320,200,"X-SHEAR"); 	// X-shear
drawpoly(n,a4);
			delay(1000);   
cleardevice(); 

setcolor(6); 
 for(int i=0;i<p;i++)
{
	if(i%2==0)
{
	a5[i]=a[i];

}
else
a5[i]=a[i]+a[i-1]*c;
}
a5[p]=a5[0];
a5[p+1]=a5[1];
outtextxy(320,300,"Y-SHEAR");	//Y-shear
drawpoly(n,a5);
			delay(10000);   
cleardevice();       
   closegraph();

}


