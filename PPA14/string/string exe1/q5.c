#include<stdio.h>

void main()
{
    char str[100];
    int i , count = 0 , count1 = 0;

    printf("\nEnter the string = ");
    fgets(str , sizeof(str) , stdin);
    
    i = 0; 
    while(str[i] != '\n')
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
        else
        {
            if(str[i] != ' ')
            {
                count1++;
            }
        }
        i++;
    }

    printf("\nthe number of vowels = %d",count); 
    printf("\nthe number of consonants = %d",count1);   
}
