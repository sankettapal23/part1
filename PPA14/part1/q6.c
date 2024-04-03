//sum of 1 to n numbers
#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter the number =");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
           sum=sum+i;
    }
    printf("sum of all numbers is %d",sum);
    return 0;
}