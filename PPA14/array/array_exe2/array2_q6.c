#include<stdio.h>

void main()
{
    /* Q 6) Write a C program to create an array of n elements using static memory 
      allocation from user and print second maximum element in given array.*/

      int i = 0 , j , n , max , s_max , arr[100];

      printf("Enter how many element in array = ");
      scanf("%d",&n);
      
      printf("Enter the array element = ");
      for(i = 0; i < n; i++)
      {
        scanf("%d\n",&arr[i]);
      }
      
      printf("The array is = ");
      for(i = 0; i < n; i++)
      {
        printf("%d\t",arr[i]);
      }
      
      max = arr[0];
      s_max = arr[0];
      for(i = 0; i < n; i++)
      {
        
        for(j = 0; j < n; j++)
        {
            
            if(arr[i] < max)
            {
                s_max = max;
                max = arr[j];
            }
        }
      }
      printf("\nsecond maximum element is = %d",s_max);
 
}