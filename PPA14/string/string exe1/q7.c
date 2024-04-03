#include<stdio.h>

void main()
{
    char str[100];
    int i = 0 , j;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);
    printf("\n");
    while(str[i] != '\n')
    {
        if(str[i] != ' ')
        {
            printf("%c",str[i]);
        }
        else if (str[i] == ' ')
        {
            printf("$");
        }
        i++;
        
    }
}