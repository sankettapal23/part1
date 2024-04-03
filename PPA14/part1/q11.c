//first and last digit of number
#include<stdio.h>
int main()
{ 
    int n;
    printf("Enter number =");
    scanf("%d",&n);
    int last_digit;
    int first_digit;
    last_digit=n%10;
    while(n>=10)
    {
        n = n / 10;
    }
    first_digit=n;
    printf("First Digit =%d\nLast digit =%d",first_digit,last_digit);
    return 0;
}