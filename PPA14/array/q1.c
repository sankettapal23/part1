#include<stdio.h>
void main()
{
 int n,num,ans,i,rem;
 int arr[100];
 printf("Enter total no of element in array\n");
 scanf("%d",&n);
 printf(" enter Array elements ");
 for(i=0;i<n;i++)
 {
    scanf("%d",&arr[i]);
 }
 printf("Array elements are ");
 for(i=0;i<n;i++)
 {
    printf("%d\n",arr[i]);
 }
 printf("palindrome elemnts are ");
 for(i=0;i<n;i++)
 {
  num=arr[i];
  ans=0;
  while(num>0)
  {
    rem=num%10;
    ans=ans*10+rem;
    num=num/10;
  }
  if(ans==arr[i])
  {
    printf("%d\n",arr[i]);
  }
 }
}