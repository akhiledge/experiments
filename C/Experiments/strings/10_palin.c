#include<stdio.h> 
#include<stdlib.h>
int main(void) 
{
    char *str=(char *)malloc(sizeof(char)*50);
    printf("enter string:");
    scanf("%s",str); 
    int flag=0,i,len=0;
    for(len=0;str[len]!='\0';len++);
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-1-i])
        {
            flag=1;
            break;
        }
    }
    printf("the given string %s is %spalindrome\n",str,(flag==1?"not ":""));
    return 0;
}
