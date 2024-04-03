#include<stdio.h>

void main()
{
    /* Q 4) Write a C program to create an array of n elements using static memory 
    allocation to insert new value in the array (sorted list).*/


    int i , n , j , temp , arr[100] , new;

    printf("Enter how many number in array = ");
    scanf("%d",&n);

    printf("Enter the array element = ");
    for(i = 0; i < n-1; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n the unsorted array is = ");
    for(i = 0; i < n-1; i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\n the sorted array is = ");
    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i = 0; i < n-1; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\nEnter the element = ");
    scanf("%d",&arr[n]);
    
    for(i = n; i >= 0; i--)
    {
        j = i - 1; 
        if(arr[i] < new)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n the sorted array is = ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    


    
}