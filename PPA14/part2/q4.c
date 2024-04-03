//reverse no
#include<stdio.h>
int main()
{
    int n, rev, rem,org;
    printf("Enter the number =");
    scanf("%d",&n);
    rev=0;
    org=n;
    while(n>0)
    {
        rem = n % 10 ; 
        rev = rev*10 + rem ;
        n = n / 10;
    }
    printf("Reverse number of %d is = %d", org,rev);
    return 0 ;
}