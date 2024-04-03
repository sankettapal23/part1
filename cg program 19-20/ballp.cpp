#include<graphics.h>
#include<iostream>
using namespace std;

void circle(int xc,int yc,int rad);

int main()
{
 int xc,yc,rad,i,j,k=100;

 //cout<<"Enter starting and ending point";
 //cin>>xc>>yc;

 cout<<"Enter the radius";
 cin>>rad;


 int gd=DETECT, gm=VGAMAX;
               initgraph(&gd, &gm, 0);
 setcolor(GREEN);

    for(j=0;j<10;j++)
       {

         for(i=100;i<200;i++)
            {
              cleardevice();
              line(0,200+rad,1000,200+rad);
              circle(k,i,rad);
	      floodfill(k,i,7);

              delay(10);

             
 
              k++;
            }
  for(i=200;i>100;i--)
     {
        cleardevice();
        line(0,200+rad,1000,200+rad);
        circle(k,i,rad);
        floodfill(k,i,7);
         
        delay(10);
        


        k++;
   }
 }



  delay(1000);
  closegraph();


 return 0;
}



