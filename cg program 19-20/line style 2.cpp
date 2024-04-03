#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
void DDA(int x1, int y1,int x2,int y2);
void DDA1(int x1, int y1,int x2,int y2);
void DDA2(int x1, int y1,int x2,int y2);
void DDA3(int x1, int y1,int x2,int y2);
void DDA4(int x1, int y1,int x2,int y2, float width);
int main()
{
	       int x1,x2,y1,y2,ch;
		float width;
		char ch1;
		do{
               int gd=DETECT, gm=VGAMAX;
		cout<<"\nEnter start points\n";
		cin>>x1>>y1;
		cout<<"\nEnter the End points\n";
		cin>>x2>>y2;
		cout<<"Which line do u want? 1.Continuous line 2.Dotted line 3.Dashed dotted 4.Dashed 5.Thick line\n";
		cin>>ch;
		
		switch(ch){
                case 1:
		initgraph(&gd, &gm, 0);
		DDA(x1,y1,x2,y2);
		delay(5000);
		closegraph();break;
		case 2:
		initgraph(&gd, &gm, 0);
		DDA1(x1,y1,x2,y2);
		delay(5000);
		closegraph();break;
		case 3:
		initgraph(&gd, &gm, 0);
		DDA2(x1,y1,x2,y2);
		delay(5000);
		closegraph();break;
		case 4:
		initgraph(&gd, &gm, 0);
		DDA3(x1,y1,x2,y2);
		delay(5000);
		closegraph();break;
		case 5:
		cout<<"\nEnter the width of line\n";
		cin>>width;
		initgraph(&gd, &gm, 0);
		DDA4(x1,y1,x2,y2,width);
		delay(5000);
		closegraph();break;
		default : break;
		}
		cout<<"\n Do u want to continue?(Y/y)\n";
		cin>>ch1;
		}while(ch1=='y' || ch1=='Y');
		return 0;
}
void DDA(int x1,int y1, int x2, int y2)
{
float xinc,yinc;
int i,Dx,Dy,steps,x,y,xp,yp,ch;
Dx=x2-x1;
Dy=y2-y1;
if(abs(Dx)>=abs(Dy))
	steps=Dx;
else
	steps=Dy;
xinc=Dx/steps;
yinc=Dy/steps;
putpixel(x1,y1,RED);
x=x1;
y=y1;
for(i=0;i<steps;i++)
{
x=x+xinc;
y=y+yinc;
xp=x+0.5;
yp=y+0.5;
putpixel(xp,yp,RED);
}
}
void DDA1(int x1,int y1, int x2, int y2)
{
float xinc,yinc;
int i,Dx,Dy,steps,x,y,xp,yp,ch;
Dx=x2-x1;
Dy=y2-y1;
if(abs(Dx)>=abs(Dy))
	steps=Dx;
else
	steps=Dy;
xinc=Dx/steps;
yinc=Dy/steps;
putpixel(x1,y1,RED);
x=x1;
y=y1;
for(i=0;i<steps;i++)
{
x=x+xinc;
y=y+yinc;
xp=x+0.5;
yp=y+0.5;
if(xp%6==0)
putpixel(xp,yp,RED);
}
}

void DDA2(int x1,int y1, int x2, int y2)
{
float xinc,yinc;
int i,Dx,Dy,steps,x,y,xp,yp,ch;
Dx=x2-x1;
Dy=y2-y1;
if(abs(Dx)>=abs(Dy))
	steps=Dx;
else
	steps=Dy;
xinc=Dx/steps;
yinc=Dy/steps;
putpixel(x1,y1,RED);
x=x1;
y=y1;
for(i=0;i<steps;i++)
{
x=x+xinc;
y=y+yinc;
xp=x+0.5;
yp=y+0.5;
if(x%2==0||x%3==0)
putpixel(xp,yp,RED);
}
}
void DDA3(int x1,int y1, int x2, int y2)
{
float xinc,yinc;
int i,Dx,Dy,steps,x,y,xp,yp,ch;
Dx=x2-x1;
Dy=y2-y1;
if(abs(Dx)>=abs(Dy))
	steps=Dx;
else
	steps=Dy;
xinc=Dx/steps;
yinc=Dy/steps;
putpixel(x1,y1,RED);
x=x1;
y=y1;
for(i=0;i<steps;i++)
{
x=x+xinc;
y=y+yinc;
xp=x+0.5;
yp=y+0.5;
if(x%2!=0||x%3!=0)
putpixel(xp,yp,RED);
}
}
void DDA4(int x1,int y1, int x2, int y2, float width)
{
float xinc,yinc,Dx,Dy,steps,x,y,xp,yp,ch;
int i,j;
Dx=x2-x1;
Dy=y2-y1;
if(abs(Dx)>=abs(Dy))
	steps=Dx;
else
	steps=Dy;
xinc=Dx/steps;
yinc=Dy/steps;
for(j=0;j<width;j++)
putpixel(x1+j,y1,RED);
x=x1;
y=y1;
for(i=0;i<steps;i++)
{
x=x+xinc;
y=y+yinc;
xp=x+0.5;
yp=y+0.5;
for(j=0;j<width;j++)
putpixel(xp+j,yp,RED);
}
}
