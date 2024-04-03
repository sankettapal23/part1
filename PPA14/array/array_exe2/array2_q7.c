#include<stdio.h>

void main()
{
    /* Q 7) Write a C program to create an array of n elements using static memory 
    allocation from user and print only those elements which are divisible by 
    7 and not divisible by 5.*/

    int n , i ,arr[100];

    printf("Enter the number of element in array = ");
    scanf("%d",&n);

    printf("Enter the array element = ");
    for (i = 0; i < n; i++)
    {
        scanf("\n%d",&arr[i]);
    }

    printf(" the array element is = ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    printf("\nthe array element witch is divisible by 5 and 7 is = ");
    for(i = 0; i < n; i++)
    {
        if(arr[i] % 5 == 0 && arr[i] % 7 == 0)
        {
            printf("%d\t",arr[i]);
        }
    }


}