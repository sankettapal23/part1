//5.prime factors program 
#include<stdio.h>
int main()
{
    int n,i,j,count;
    printf("Enter the number\n");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++)
    {
        if(n%i==0)
        {
            //printf("%d\n",i);
            count = 0;
            for(j=1 ; j<=i ; j++)
            {
                if(i%j==0)
                {
                    count++;
                }

            }
            if(count == 2)
            {
                printf("prime divisor =%d\n",i);
            }
        }
    }
    return 0;
}