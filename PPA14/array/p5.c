#include<stdio.h>
void main()
{
 int n,j, i,temp;
 int arr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf("Enter Array of Element\n");
 for(i=0;i<n;i++)
 { printf("Enter a element ");
   scanf("%d",&arr[i]);
 }

for(i=0;i<n;i++)
 { 
    for(j=(i+1);j<n;j++)
    { if(arr[i]>arr[j])
       { temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       }
    }
 } 
int mid=n/2;    
for(i=mid+1;i<n;i++)
   { for(j=i+1;j<n;j++)
    { if(arr[i]<arr[j])
       { temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       }
    } 
   }
 
for(i=0;i<n;i++)
 {
   printf("\n arr elements are %d",arr[i]);
 }

}
