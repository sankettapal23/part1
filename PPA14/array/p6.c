#include<stdio.h>
void main()
{
 int n, i ,j=0,k,temp;
 int arr[100],brr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf("Enter Array of Element\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }
 printf("%d",arr[i]);
 for(i=0;i<n;i++)
 {
    if(arr[i]%2==0)
    {
        brr[j]=arr[i];
        j++;
    }
 }
 
 
 for(i=0;i<j;i++)
  {
    for(k=i+1;k<j;k++)
     {
         temp=brr[i];
         brr[i]=brr[k];
         brr[k]=temp;
     }

  }
k=0;
for(i=0;i<n;i++)
 {
    if(arr[i]%2==0)
    {
        arr[i]=brr[k];
        k++;
    }
 }
for(i=0;i<n;i++)
 {
   printf("%d\n",&arr[i]);
 }
 printf("\n");
}