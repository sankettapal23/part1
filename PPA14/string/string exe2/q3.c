#include<stdio.h>
int main()
{   int i=0,count,even=0,odd=0;
    char str[100];
    printf("Enter the string:- ");
    fgets(str,sizeof(str),stdin);
    printf("%s\n",str);

    while(str[i]!='\n')
    {   
        count=0;
        while(str[i]!=' ' && str[i+1]!='\0')
        {  
         i++;
         count++; 
        }
        if(count%2==0)
            {
               even++;              
            }
        else
            {
                odd++;                
            }
        while(str[i]==' ')    
        {
          i++;
        }       
    }
    printf("Total Even length words are= %d\n",even);
    printf("Total Odd length words are= %d\n",odd);
   
    return(0);
}