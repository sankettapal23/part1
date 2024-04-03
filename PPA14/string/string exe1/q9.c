#include<stdio.h>

void main()
{
    char str[100] = "hello Goodname";
    char user[100];
    int i = 0 , count = 0;;

    printf("%s",str);
    printf("\nEnter the string = ");
    fgets(user , sizeof(user) , stdin);

    while(str[i] != '\n')
    {
        if(str[i] == 'G')
        {
            printf("%s",user);
            break;
        }
        printf("%c",str[i]);
        i++;
    }
}