#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
int main(void) 
{
    int len=0,i;
    char *str=(char *)malloc(sizeof(char)*50);
    printf("enter string:");
    scanf("%s",str);
    for(len=0;str[len]!='\0';len++);
    for(i=0;i<len-1;i++)
    {
        if(str[i]==str[i+1])
        {
            /*int j=i;
            while(str[j]!='\0')
            {
                str[j]=str[j++];
            }*/
            memmove(&str[i],&str[i+1],len-i);
            len--;
            i--;
        }
    }
    printf("the string is %s\n",str);
    return 0;

}

