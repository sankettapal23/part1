//GCD of two numbers
#include<stdio.h>
void main()
{
  int num1,num2,i,gcd;
  printf("enter first no.\n");
  scanf("%d",&num1);
  printf("enter first no.\n");
  scanf("%d",&num2);
  for(i=1;i<=num1 &&i<=num2;i++)
  {
    if(num1%i==0&&num2%i==0)
     {
       gcd=i;
     }
  }
 printf("GCD of %d and %d is %d",num1,num2,gcd);
} 