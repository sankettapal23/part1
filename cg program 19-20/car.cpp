#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   int i,j;

 
   int gd=DETECT, gm=VGAMAX;
   initgraph(&gd,&gm, 0);
     


     for(j=0;j<5;j++)
{
	 
	for(int i=0;i<200;i++)
{
       
	line(100+i,100,200+i,100);
  	line(200+i,100,200+i,150);
	line(200+i,150,100+i,150);
	line(100+i,100,100+i,150);
	
	setcolor(1);
	setcolor(1);
	circle(120+i,150,10);
	circle(180+i,150,10);
	floodfill(120+i,150,1);
	floodfill(180+i,150,1);
	delay(10);
	cleardevice();
}
        line(100,0,100,600);
        line(400,0,400,600);
   delay(100);
  	for(int i=200;i>0;i--)
{

	line(100+i,100,200+i,100);
  	line(200+i,100,200+i,150);
	line(200+i,150,100+i,150);
	line(100+i,100,100+i,150);
	
	setcolor(1);
	setcolor(1);
	circle(120+i,150,10);
	circle(180+i,150,10);
	floodfill(120+i,150,1);
	floodfill(180+i,150,1);
	delay(10);
	cleardevice();
}


}
  
  closegraph();
  return 0;
}


