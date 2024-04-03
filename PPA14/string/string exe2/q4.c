#include<stdio.h>
int main()
{
    int i;
    char str[100];
    printf("Enter the string:- ");

    fgets(str,sizeof(str),stdin);
    printf("input string is= %s",str);
    while(str[i+1]!='\0')
    {
       i++;
    }   
    
    while(str[i]!=' ')
    {
        i--;
    }
 
    while(str[i+1]!='\0')
         {
           printf("%c",str[i]);
           i++;
         }
       
        
    return(0);
}