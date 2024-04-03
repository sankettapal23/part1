#include<stdio.h>
void main()
{
 int n, i,sum=0 ;
 int arr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf("Enter Array of Element\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }

for(i=0;i<n;i++)
 { sum=sum+arr[i];
   
   
}
printf("\n sum of all elements =%d",sum);
}
