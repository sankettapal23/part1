#include<stdio.h>
void main()
{
  int i,j,n;
  printf("Enter  value of n\n");
  scanf("%d",&n);
  for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
        { 
            if(j<(n-i+1))
             {
                  printf("  ");
             }
            else
            {
               printf("* ");
            }
                         
         }
       printf("\n");
    }
}