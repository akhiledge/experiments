#include<stdio.h> 
#include<string.h>
#include<stdlib.h> 
char * sappend(char *str1, char *str2)
{
    int i=0,len=strlen(str2)-1,len1=strlen(str1);
    printf("%d %d",len1,len);     
    while(i<(len1-1))
    {
        str2[len]=str1[i];
        i++;
        len++;
    } 
    str2[len]='\0';
    printf("\n%s\n",str2); 
    return str2;
}

int main(void) 
{
    char *str1,*str2;
    str1=(char *)malloc(sizeof(char)*50);
    str2=(char *)malloc(sizeof(char)*50);
    printf("enter str1:");
    fgets(str1,50,stdin);
    printf("enter str2:");
    fgets(str2,50,stdin);
    str2=sappend(str1,str2);
    printf("str1=%s str2=%s",str1,str2);


    return 0;
}

