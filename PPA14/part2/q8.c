// power of number
#include <stdio.h>
void main()
{
  int a, exp,ans=1,i;
  printf("Enter the value of a\n");
  scanf("%d",&a);
  printf("Enter the value of exponent\n");
  scanf("%d",&exp);
  for(i=1;i<=exp;i++)
   {
     ans=ans*a;
   }
  printf("Answer=%d",ans);
}