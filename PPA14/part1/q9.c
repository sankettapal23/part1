//table of any  no
#include<stdio.h>
void main()
{ int i;
  int n;
  int ans;
  printf("Enter the value of n\n");
  scanf("%d",&n); 
  for(i=1; i<=10;i++)
  { 
    ans=n*i;
    printf("%d\n",ans);
  }
}