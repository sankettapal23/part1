#include<stdio.h>
void main()
{
 int n, i ;
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
   printf("arr[%d]=%d",i,arr[i]);
   printf("\n");
}
}
