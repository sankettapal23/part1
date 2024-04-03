#include<stdio.h>
void main()
{
  int n,i,ans=1;
  printf("Enter the value of n\n");
  scanf("%d",&n);

  for (i=1;i<=n;i++)
  {
    ans=ans*i;
  }
 printf("%d  ",ans);
}