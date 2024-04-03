/*
/  Bresenham circle drawing algorithm
*/
#include<iostream>
#include<graphics.h>
using namespace std;
void draw(int x,int y,int xc,int yc);
void cir(int xc,int yc,int r);
int main()
{
 int x, y, r;
 cout<<"Enter centre co-ordinates\n";
 cout<<"X: ";
 cin>>x;
 cout<<"Y: ";
 cin>>y;
 cout<<"Radius: ";
 cin>>r;
 int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
 cir(x,y,r);
 delay(100);
 closegraph();
 return 0;
}

void cir(int xc,int yc,int r)
{
 int d;
 int x,y;
 x=0;
 y=r;
 d=3-2*r;
 draw(x,y,xc,yc);
 while(x<=y)
 {
  x++;
  if(d<0)
   d=d+4*x+6;
  else
  {
   y=y-1;
   d=d+4*x-4*y+10;
  }
  draw(x,y,xc,yc);
 }
}

void draw(int x,int y,int xc,int yc)
{
 putpixel(xc+x,yc+y,1);
 delay(3);
 putpixel(xc+y,yc+x,2);
 delay(3);
 putpixel(xc-y,yc+x,3);
 delay(3);
 putpixel(xc-x,yc+y,4);
 delay(3);
 putpixel(xc-x,yc-y,5);
 delay(3);
 putpixel(xc-y,yc-x,6);
 delay(3);
 putpixel(xc+y,yc-x,7);
 delay(3);
 putpixel(xc+x,yc-y,8);
}
