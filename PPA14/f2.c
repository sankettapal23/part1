#include<stdio.h>
void main()
{
 int n, i,search, flag=0;
 int arr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf("Enter element want to search in array\n");
 scanf("%d",&search);
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
for(i=0;i<n;i++)
{
  if(search==arr[i])
  { flag=1;
   printf("Element found atarr[%d]",i);
   break;
  }
}
if(flag==0)
 { 
  printf("Element is not Found");
 }
}