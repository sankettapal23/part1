#include<stdio.h>
int main()
{
    int n,i,j;
    printf("enter number\n");
    scanf("%d",&n);
    for(j=1 ; j<=n ; j++)
    {
        for(i=1 ; i<=j ; i++)
        {
            printf("%d ",j);   // replace j with i for getting 1 2 3 4 5...n
        }
        printf("\n");

    }
    return 0;

}