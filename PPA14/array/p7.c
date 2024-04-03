#include<stdio.h>
void main()
{
 int n,j, i,count=0,flag;
 int arr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf("Enter Array of Element\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }
 for(i=0;i<n;i++)
  { count=0;
    j=i-1;
    while(j>=0)
    {
        if(arr[i]==arr[j])
        {
            flag=1;
            break;
        }
        j--;
    }
    if(flag=1)
    {
      i++;
    }
    else
    {
     for(j=0;j<n;j++)
       {
        if (arr[i]==arr[j])
        {
            count++;
        }
       }
    printf("%d=%d\n",arr[i],count);
 }
}
}