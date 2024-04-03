#include<stdio.h>


int can_partition(int* , int );
int is_possible(int*, int , int ,int);


void main()
{
    int result;
    int arr[]={1,5,11,5};
    int n=4;
    result = can_partition(arr,n);
    if(result == 0)
    {
        printf("False\n");
    }
    else
    {
        printf("True\n");
    }
}

int can_partition(int arr[], int n)
{
    int total_sum=0;
    int i;
    for(i=0 ; i<n ; i++)
    {
        total_sum=arr[i];
    }
    if(total_sum % 2 != 0)
    {
        return 0;
    }
    return is_possible(arr,0,total_sum/2,n);
}

int is_possible(int arr[], int current_ind , int target_sum,int n)
{
    int consider, not_consider;
    
    if(target_sum == 0)
    {
        return 1;
    }
    if(target_sum < 0 || current_ind >= n)
    {
        return 0;
    }
    consider=is_possible(arr,current_ind+1,target_sum - arr[current_ind],n);
    not_consider=is_possible(arr,current_ind+1,target_sum,n);
    return consider || not_consider;
}