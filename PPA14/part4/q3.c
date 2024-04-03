// 1 to n prime numbers
#include<stdio.h>
void main()
{
   int limit,n,i,count=0,sum=0;
   printf("Enter the limit\n");
   scanf("%d",&limit);
   for(n=1;n<=limit;n++)
   { count=0;
      
   for(i=1;i<=n;i++)
      {
        if(n%i==0)
         { 
          count++;
         }
      }
   
  if (count==2)
  { sum=sum+n;
    printf("%d is prime no\n",n);
  }
 }
printf("Sum of all prime no is %d",sum);
}
  