#include<stdio.h>

void main()
{
    char str[100];

    printf("Enter the the string = ");
    fgets(str , sizeof(str) , stdin);

    printf("%s",str);
}