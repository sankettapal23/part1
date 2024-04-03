#include<stdio.h>

void main()
{
    char str[100];
    int i = 0 , count = 0;;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);

    while (str[i] != '\n')
    {
        if(str[i] != ' ' && str[i+1] == ' ')
        {
            count++;
        }
        i++;
    }
    printf("There is %d word in given sentence.",count+1);
    
}