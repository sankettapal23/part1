#include<stdio.h>

int maxprofit(int *,int *,int,int,int);
int max(int,int);

int main()
{
    int max;
    int n=3;
    int capacity=4;
    int weight[]={1,2,3};
    int profit[]={4,5,1};

    max= maxprofit(weight,profit,0,n,capacity);
    printf("Maximum profit is=%d" ,max);
    return 0;
}



int maxprofit(int* weight,int* profit,int CI,int n,int capacity)
{   
    int consider,noconsider;
    capacity=capacity-weight[CI];
    if(CI==n  || capacity<0)
    {
        return 0;
    }
    
    
    consider=profit[CI]+ maxprofit(weight,profit,CI+1,n,capacity);

    noconsider= maxprofit(weight,profit,CI+1,n,capacity);

    return (max(consider,noconsider));
}

int max(int n1,int n2)
{
    return(n1>n2?n1:n2);
}


