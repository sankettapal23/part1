// sum of first and last digit of nummber
#include<stdio.h>
int main()
{
    int n;
    int first;
    int last;
    int sum;
    printf("Enter the number =");
    scanf("%d",&n);
    last=n%10;
    while(n>=10)
    {
        n =n / 10;

    }
    first = n;
    sum = first + last;
    printf("Sum of first and last digit = %d",sum);
    return 0 ;

}