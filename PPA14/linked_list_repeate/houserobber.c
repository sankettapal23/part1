#include<stdio.h>

int max(int,int);
int maxmoney(int*, int,int);

int main()
{
    int val;
    int nums[]={2,7,9,3,1};
    int n=5;
    val=maxmoney(nums,0,n);
    printf("\n => %d",val);
    
    return (0);
}

int maxmoney(int* nums, int current_house, int n)
{
    int rob,notrob;
    if(current_house>= n)
    {
        return 0;
    }

    rob=nums[current_house]+maxmoney(nums,current_house +2,n);
    notrob=maxmoney(nums,current_house+1,n);

    return max(rob,notrob);
    

}

int max(int n1, int n2)
{
    return n1>n2?n1:n2;
}