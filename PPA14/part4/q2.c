//prime no
#include<stdio.h>
void main()
{
   int n,i,count=0;
   printf("Enter the number\n");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      if(n%i==0)
        { 
          count++;
        }
   }
  if (count==2)
  {
    printf("%d is prime no",n);
  }
 else
 {
   printf("%d is not prime no.",n);
  }
}  