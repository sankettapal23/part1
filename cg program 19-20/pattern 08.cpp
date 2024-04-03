/*
/  Inscribed and circumscribed circle over triangle
*/
#include<iostream>
#include<graphics.h>
using namespace std;
void draw(int x,int y,int xc,int yc);
void cir(int xc,int yc,int r);
void dda(int x1, int y1, int x2, int y2);
int main()
{
 int x,y,r;
 cout<<"Enter centre co-ordinates of circle\n";
 cout<<"X: ";
 cin>>x;
 cout<<"Y: ";
 cin>>y;
 cout<<"Radius: ";
 cin>>r;
 int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
 cir(x,y,r);
 dda(x,y-r,x+(1.7321*r)/2,y+r/2);
 dda(x+(1.7321*r)/2,y+r/2,x-(1.7321*r)/2,y+r/2);
 dda(x-(1.7321*r)/2,y+r/2,x,y-r);
 cir(x,y,r/2);
 delay(10000);
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
 delay(5);
 putpixel(xc+y,yc+x,2);
 delay(5);
 putpixel(xc-y,yc+x,3);
 delay(5);
 putpixel(xc-x,yc+y,4);
 delay(5);
 putpixel(xc-x,yc-y,5);
 delay(5);
 putpixel(xc-y,yc-x,6);
 delay(5);
 putpixel(xc+y,yc-x,7);
 delay(5);
 putpixel(xc+x,yc-y,8);
}

void dda(int x1, int y1, int x2, int y2)
{
 float len, i=0, xinc, yinc, x, y;
 int Dx, Dy;
 Dy=y2-y1;
 Dx=x2-x1;
 if(abs(Dx)>=abs(Dy))
  len=abs(Dx);
 else
  len=abs(Dy);
 xinc=Dx/len;
 yinc=Dy/len;
 x=x1;
 y=y1;

 while(i<=len)
 {
  putpixel(x,y,RED);
  delay(5);
  x=x+xinc;
  y=y+yinc;
  i++;
 }

}
