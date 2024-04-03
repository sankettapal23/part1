/*
/  Digital Differential Analyzer (DDA) & Bresenham's line drawing algorith
*/

#include<iostream>
#include<graphics.h>
using namespace std;
int sign(int a);
void dda(int x1, int y1, int x2, int y2);
void bres(int x1, int y1, int x2, int y2);

int sign(int a)
{
 if(a<0)
  return (-1);
 if(a>0)
  return (1);
 return (0);
}

int main()
{
 int x1, y1, x2, y2, n;
 label:
 cout<<"1)DDA\n2)Bresenham\nChoose any option: ";
 cin>>n;
 if(n==1 || n==2)
 {
 cout<<"Enter first point\n";
 cout<<"X1: ";
 cin>>x1;
 cout<<"Y1: ";
 cin>>y1;
 cout<<"Enter second point\n";
 cout<<"X2: ";
 cin>>x2;
 cout<<"Y2: ";
 cin>>y2;
 if(n==1)
  dda(x1,y1,x2,y2);
 else 
  bres(x1,y1,x2,y2);
 }
 else
 {
  cout<<"*** Choose correct option !!!"<<endl;
  goto label;
 }
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
 int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
 while(i<=len)
 {
  putpixel(x,y,RED);
  x=x+xinc;
  y=y+yinc;
  i++;
 }
 delay(10000);
 closegraph();
}

void bres(int x1, int y1, int x2, int y2)
{
 int Dx, Dy, s1, s2, x, y, ex=0, G, i;
 Dx=abs(x2-x1);
 Dy=abs(y2-y1);
 s1=sign(x2-x1);
 s2=sign(y2-y1);
 if(Dy>Dx)
  ex=1;
 if(ex==1)
 {
  i=Dx;
  Dx=Dy;
  Dy=i;
 }
 x=x1;
 y=y1;
 int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
 putpixel(x,y,RED);
 G=2*Dy-Dx;
 for(i=0;i<=Dx;i++)
 {
  while(G>=0)
  {
   if(ex==1)
    x=x+s1;
   else
    y=y+s2;
   G=G-2*Dx;
  }
  if(ex==1)
   y=y+s2;
  else
   x=x+s1;
  G=G+2*Dy;
  putpixel(x,y,RED);
 }
 delay(10000);
 closegraph();
}

