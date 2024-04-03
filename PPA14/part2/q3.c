//product of digits of given number
#include<stdio.h>
int main()
{
    int n,prod,rem;
    printf("Enter the number = ");
    scanf("%d",&n);
    prod=1;
    while(n>0)
    {
        rem = n % 10 ;
        prod = prod * rem ; 
        n = n / 10;

    }
    printf("product = %d", prod);
    return 0 ;
    }