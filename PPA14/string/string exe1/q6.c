#include<stdio.h>

void main()
{
    char str[100] , temp[10];
    int i = 0 , j = 0 , k = 0 , l = 0 , count;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);

    while(str[i] != '\n')
    {
        k = i;
        if(str[k] != ' ' && k >= 0)
        {
            while(str[k] != ' ')
            {
                k++;
            }
            while(str[k] != ' ')
            {
                printf("%c",str[j]);
                k--;
            }
            k = i;
            
            
        }
        i++;
    } 
}