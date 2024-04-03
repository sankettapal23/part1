#include<stdio.h>

void main()
{
    int i = 0;
    char str[100];

    printf("Enter the string = ");
    fgets(str , sizeof(str) , stdin);

    while(str[i]=='\n')
    {
        while(str[i]==' ')
        {
            i++;
        }

        while(str[i]!=' ')
        {
            
            if(str[i+1] == ' ' && str[i+1] != '\n')
            {
                printf(" ");
            }
            i++;
        }
        printf("%c",str[i]);
    }

}