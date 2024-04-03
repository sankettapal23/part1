#include<stdio.h>
void dolike()
{
 static int like=0;
 like=like+1;
 printf("%d\n",like);
}
int main()
{
    dolike();
    dolike();
    dolike();
    dolike();
    dolike();
    dolike();
    dolike();
    dolike();
    dolike();
    dolike();
    return (0);
}