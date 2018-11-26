#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
int main(void)
{
    int len,i=0;
    char str[50],t;
    printf("enter string:");
    fgets(str,50,stdin);
    len=strlen(str);
    for(i=0;i<(len/2);i++)
    {
        t=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=t;
    }
    
    printf("\n%s",str);
    return 0;


}
