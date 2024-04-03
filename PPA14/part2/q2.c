//sum of digits
#include<stdio.h>
int main()
{
    int n,rem,sum;
    printf("Enter the number =");
    scanf("%d",&n);
    sum=0;
    while(n>0)
    {
        rem=n%10;
        sum = sum + rem;
        n = n / 10;
    }
    printf("Sum of digits = %d",sum);
    return 0;
}