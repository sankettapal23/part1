#include<iostream>
#include<graphics.h>
using namespace std;

//putpixel
void draw(int x,int y,int xc,int yc)
{
putpixel (xc+x,yc+y,1);
delay(100);
putpixel (xc+y,yc+x,2);
delay(100);
putpixel (xc+x,yc-y,3);
delay(100);
putpixel (xc-x,yc+y,4);
delay(100);
putpixel (xc-y,yc+x,5);
delay(100);
putpixel (xc+y,yc-x,6);
delay(100);
putpixel (xc-x,yc-y,7);
delay(100);
putpixel (xc-y,yc-x,8);
delay(100);
}

//bresenham's algorithm
void circl(int xc,int yc,int r)
{ 
int d,x,y;
x=0;
y=r;
d=3-2*r;
 draw(x,y,xc,yc);
while(x<=y)
{
if(d<=0)
{
d=d+4*x+6;
x=x+1;
y=y;
 draw(x,y,xc,yc);
}
else
{
d=d+4*x-4*y+10;
x=x+1;
y=y-1;
draw(x,y,xc,yc);
}
}
}


//main Function
int main()
{

int xc,yc,r;
int xp,yp,r2;

cout<<"enter the center & radius of circle";
cin>>xc>>yc>>r;


               int gd=DETECT, gm=VGAMAX;
               initgraph(&gd, &gm, 0);
            	void circl(int xc,int yc,int r);

		void draw(int x,int y,int xc,int yc);

  		circl(xc,yc,r);

		delay(10);
               closegraph();

return (0);
}
