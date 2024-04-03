#include<stdio.h>
int main()
{   int i=0,cap=0,sml=0,sp=0,num=0;
    char str[100];
    printf("Enter the string:- ");

    fgets(str,sizeof(str),stdin);
    printf("%s",str);

    while(str[i]!='\n')
    {
        if(str[i]>='A' && str[i]<='Z')
          {
            cap++;
            
          }
        else if(str[i]>='a' && str[i]<='z')
        {
            sml++;
            
        }
        else if(str[i]==' ')
        {
            sp++;
            
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            num++;
            
        }
        i++;
               
    }
    printf("Total no of capital letters are = %d\n",cap);
    printf("Total no of small letters are = %d\n",sml);
    printf("Total no of spaces are = %d\n",sp);
    printf("Total no of numbers are = %d\n",num);
    return(0);
}