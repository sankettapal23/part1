#include<stdio.h>
void main()
{
 int n, i, min=99;
 int arr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf("Enter Array of Element\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }
printf("Array elements are\n");
for(i=0;i<n;i++)
 {
   if(arr[i]<min)
   {
     min=arr[i];
   }
}
 printf("Smallest no is=%d",min);
}
