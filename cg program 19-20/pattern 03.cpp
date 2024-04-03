/*
/  Square Pattern
*/
#include<iostream>
#include<graphics.h>
using namespace std;
void dda(int x1, int y1, int x2, int y2);
int main()
{
 int x, y, d;
 cout<<"X: ";
 cin>>x;
 cout<<"Y: ";
 cin>>y;
 cout<<"Length: ";
 cin>>d;
 int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
 dda(x,y,x+d,y);
 dda(x+d,y,x+d,y+d);
 dda(x+d,y+d,x,y+d);
 dda(x,y+d,x,y);
 dda(x,y+d/2,x+d/2,y);
 dda(x+d/2,y,x+d,y+d/2);
 dda(x+d,y+d/2,x+d/2,y+d);
 dda(x+d/2,y+d,x,y+d/2);
 dda(x+d/4,y+d/4,x+((3*d)/4),y+d/4);
 dda(x+((3*d)/4),y+d/4,x+((3*d)/4),y+((3*d)/4));
 dda(x+((3*d)/4),y+((3*d)/4),x+d/4,y+((3*d)/4));
 dda(x+d/4,y+((3*d)/4),x+d/4,y+d/4);
 delay(10000);
 closegraph();
 return 0;
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
  putpixel(x,y,5);
  delay(5);
  x=x+xinc;
  y=y+yinc;
  i++;
 }
}
