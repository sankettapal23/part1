#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
int n, a[30][2], b[30][2], c[30][2], tx, ty, sx, sy, r;
void translation();
void scaling();
void rotation();
int main()
{
 int i;
 cout<<"*** Note:- First point entered will be taken as arbitary point ***\n\n";
 cout<<"Enter the number of edges of polygon: ";
 cin>>n;
 cout<<"Enter the cordinates of polygon:\n";
 for(i=0;i<n;i++)
 {
  cout<<"X["<<i+1<<"]: ";
  cin>>a[i][0];
  cout<<"Y["<<i+1<<"]: ";
  cin>>a[i][1];
 }
 a[n][0]=a[0][0];
 a[n][1]=a[0][1];
 cout<<"Tx: ";
 cin>>tx;
 cout<<"Ty: ";
 cin>>ty;
 cout<<"Sx: ";
 cin>>sx;
 cout<<"Sy: ";
 cin>>sy;
 cout<<"Angle of rotation: ";
 cin>>r;
 int gd=DETECT, gm=VGAMAX;
 initgraph(&gd, &gm, 0);
 for(i=0;i<n;i++)
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
 delay(2000);
 cleardevice();
 translation();
 for(i=0;i<n;i++)
  line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
 delay(2000);
 cleardevice();
 scaling();
 for(i=0;i<n;i++)
  line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
 delay(2000);
 cleardevice();
 rotation();
 for(i=0;i<n;i++)
  line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
 delay(2000);
 cleardevice();
 delay(1000);
 closegraph();
 return 0;
}

void translation()
{
 int i;
 for(i=0;i<=n;i++)
 {
  b[i][0]=a[i][0]+tx;
  b[i][1]=a[i][1]+ty;
 }
}

void scaling()
{
 int i;
 for(i=0;i<=n;i++)
 {
  b[i][0]=a[i][0]-a[0][0];
  b[i][1]=a[i][1]-a[0][1];
 }
 for(i=0;i<=n;i++)
 {
  c[i][0]=b[i][0]*sx;
  c[i][1]=b[i][1]*sy;
 }
 for(i=0;i<=n;i++)
 {
  b[i][0]=c[i][0]+a[0][0];
  b[i][1]=c[i][1]+a[0][1];
 }
}

void rotation()
{
 int i;
 for(i=0;i<=n;i++)
 {
  b[i][0]=a[i][0]-a[0][0];
  b[i][1]=a[i][1]-a[0][1];
 }
 for(i=0;i<=n;i++)
 {
  c[i][0]=cos((r*3.1416)/180)*b[i][0]-sin((r*3.1416)/180)*b[i][1];
  c[i][1]=sin((r*3.1416)/180)*b[i][0]+cos((r*3.1416)/180)*b[i][1];
 }
 for(i=0;i<=n;i++)
 {
  b[i][0]=c[i][0]+a[0][0];
  b[i][1]=c[i][1]+a[0][1];
 } 
}
