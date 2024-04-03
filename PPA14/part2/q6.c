#include<stdio.h>
int main()
{
    //find the frequency of given input
    int n,rem1,temp1,rem2,temp2,count;
    printf("Enter the number =");
    scanf("%d",&n);
    temp1=n;
    while(temp1>0)
    {
        rem1=temp1%10;
        count=0;
        temp2=n;
        while(temp2>0)
        {
            rem2=temp2%10;
            if(rem1==rem2)
            {
                count++;
            }
            temp2 = temp2/10;
        }
        printf("frequency of %d = %d\n", rem1,count);   
        temp1 = temp1 / 10;
    }
    return 0;
}