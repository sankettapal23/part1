//Find whether number is perfect or not
#include<stdio.h>
int main()
{
    int n,temp,rem,ans,i,sum=0;
    printf("Enter the number\n");
    scanf("%d",&n);
    temp=n;
    while(temp>0)
    {
        rem=temp%10;
        ans=1;
        for(i=1;i<=rem;i++)
        {
            ans = ans * i;

        }
        sum = sum + ans;
        temp = temp / 10;
    }
    if(sum == n)
    {
        printf("%d is PERFECT NUMBER",n);
    }
    else{
        printf("%d is not PERFECT number",n);
    }
    return 0;

    
}