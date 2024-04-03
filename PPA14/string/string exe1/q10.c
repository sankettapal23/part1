#include<stdio.h>
int main()
{ 
   int i=0;
   char str[100];
   printf("Enter the string:- ");

   fgets(str,sizeof(str),stdin);
   printf("%s\n",str);
    
   while(str[i]!='\n') 
   {
    int n1=0, n2=1, n3=0;
    
    
    printf("\n%d  ",n1);
    printf("%d  ",n2);

    while(n3<=str[i])
    {
        n3=n1+n2;
        printf("%d  ",n3);
        n1=n2;
        n2=n3;
        
    } 
    i++;
    
   }
    
}