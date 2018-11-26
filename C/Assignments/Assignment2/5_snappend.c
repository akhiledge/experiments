#include<stdio.h> 
#include<string.h>
#include<stdlib.h> 
char * sappend(char *str1, char *str2,int n)
{
    int i=0,len=strlen(str2)-1;
     
    while(i<n)
    {
        str2[len]=str1[i];
        i++;
        len++;
    } 
    str2[len]='\0';
    return str2;
}

int main(void) 
{
    int n;
    char *str1,*str2;
    str1=(char *)malloc(sizeof(char)*50);
    str2=(char *)malloc(sizeof(char)*50);
    printf("enter str1:");
    fgets(str1,49,stdin);
    printf("enter str2:");
    fgets(str2,49,stdin);
    puts("enter n:");
    scanf("%d",&n);
    str2=sappend(str1,str2,n);
    printf("str1=%s str2=%s\n",str1,str2);


    return 0;
}

