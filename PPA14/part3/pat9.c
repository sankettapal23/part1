#include<stdio.h>
void main()
{
  int i,j,n,val=1;
  printf("Enter  value of n\n");
  scanf("%d",&n);
  for (i=1;i<=n;i++)
   {
      for (j=1;j<=i;j++)
        { 
           printf("%d  ",val);
           val++;
         }
       printf("\n");
    }
} 