#include<stdio.h>

void main()
{
    char str[100];
    int i = 0 , count = 0;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);
    
    while(str[i] != '\n')
    {
        count++;
        i++;
    }

    printf("the number of character in string is = %d\n",count);
}