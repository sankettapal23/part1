#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

for(i=0;i<420;i=i+10)
{
setcolor(WHITE);
line(0,270,500,270);
setcolor(RED);
circle(75+i,250,20);
//setfillstyle(75,5);
floodfill(75+i,250,RED);
delay(100);
cleardevice();

}
closegraph();
}