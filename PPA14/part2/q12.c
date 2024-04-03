// swapping two numbers using third variable
#include <stdio.h>
void main()
{
  int a,b,c;
  printf("Enter the value of a\n");
  scanf("%d",&a);
  printf("Enter the value of b\n");
  scanf("%d",&b);
  c=a;
  a=b;
  b=c;
  printf("Swaped no are a=%d,b=%d",a,b);
}