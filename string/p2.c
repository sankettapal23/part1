#include<stdio.h>
int main()
{   int i=0;
    char str[100];
    printf("enter a string :-");
    fgets(str,sizeof(str),stdin);
    
    printf("%s",&str);
    while(str[i]!='\n')
    {
        while(str[i]==' ')
        {
            i++;
        }
        while(str[i]!=' '&& str[i]!='\n')
        {
                printf("%s",str[i]);
                if(str[i+1]==' ')
                {
                    printf(" ");
                }
                i++;
        }
        printf("%s",&str);
    }
}    