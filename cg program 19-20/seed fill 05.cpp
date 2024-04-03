#include<iostream>
#include<graphics.h>
using namespace std;
void floodFill(int x,int y,int oldc,int newc);
int main()
{
int x,y;
int arr[10]={0,0,0,0,0,0,0,0,0,0};
arr[0]=100;
arr[1]=100;
arr[2]=100;
arr[3]=200;
arr[4]=200;
arr[5]=200;
arr[6]=200;
arr[7]=100;
arr[8]=100;
arr[9]=100;

  int gd=DETECT, gm=VGAMAX;
               initgraph(&gd, &gm, 0);
              drawpoly(5,arr);
    floodFill(150,150,0,4);
    delay(1000);
     closegraph();
return 0;
}
void floodFill(int x, int y, int oldc, int newc)
{
	
	if(getpixel(x,y)==oldc)
	{
		putpixel(x,y,newc);
		delay(1);
		floodFill(x+1,y,oldc,newc);
		floodFill(x, y+1,oldc,newc);
		floodFill(x-1,y,oldc,newc);
		
		floodFill(x,y-1,oldc,newc);
	}
}

