#include<stdio.h>

void main()
{
    char str[100];
    int i = 0;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);

    while(str[i] != '\n')
    {
        if(str[i] != 'a' && str[i] != 'z')
        {
           printf("%c",str[i]);
        }
        i++;
    }
}