//armstrong no
#include<stdio.h>
void main()
{
  int n,count=0,temp,rem,i,ans=1,sum=0 ;
  printf("Enter the no\n");
  scanf("%d",&n);
  temp=n;
  while(temp>0)
   {
     count++;
     temp=temp/10;
   }
  temp=n;
  while(temp>0)
  {
    ans=1;
    rem=temp%10;
    for(i=1;i<=count; i++)
      {
        ans=ans*rem;
      }
   sum=sum+ans;
   temp=temp/10;
  }
  if(n==sum)
   {
     printf("%d is a armstrong number\n",n);
   }
 else
  {
    printf("%d is  not armstrong no",n);
  }
}
    