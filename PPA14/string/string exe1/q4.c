#include<stdio.h>

void main()
{
    char str[100];
    int i , j;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);

    i = 0;
    while(str[i] != '\n')
    {
        i++;
    }
    for(j = i; j >= 0; j--)
    {
        printf("%c",str[j]);
    }

}