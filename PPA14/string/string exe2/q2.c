#include<stdio.h>
void main()
{
    int i=0,sp=0;
    char str[100];
    printf("Enter the string:- ");

    fgets(str,sizeof(str),stdin);
    printf("%s",str);

    while(str[i]!='\n')
    {
        if(str[i]==' ')
        {
            sp++;
            
        }
        i++;
    }
    printf("Total no of spaces are = %d\n",sp);      
}