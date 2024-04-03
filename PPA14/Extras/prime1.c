#include<stdio.h>
void main()
{
   int n,i,flag=0;
   printf("Enter the number\n");
   scanf("%d",&n);
   for(i=2;i<n;i++)
     {
        if (n%i==0)
         {  flag=1;
            printf("%d is not a prime ",n);
            break;
         }
     }
  if(flag==0)
  {
    printf("%d is Prime number",n);
  }
}