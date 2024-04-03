// addition of odd numbers
#include<stdio.h>
void main()
{
  int i;
  int n;
  int ans=0;
  printf("Enter value of n\n");
  scanf("%d",&n);
  for (i=1;i<=n;i++)
   { if(i%2!=0)
    {
      ans=ans+i;
     }
   }
  printf("The addition of odd no from 1 to %d=%d",n,ans);
}
