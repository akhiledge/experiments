#include<stdio.h> 
#include<stdlib.h> 
char str_cmp(char *str1,char *str2)
{
    int i;
    while(str1[i]!='\0'||str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
            return (((str1[i]-str2[i])>0)?-1:(1));
        i++;
    }
    return 0;
}
int main(void) 
{
    char *str1,*str2;
    str1=(char *)malloc(sizeof(char)*50);
    str2=(char *)malloc(sizeof(char)*50);
    puts("enter str1:");
    fgets(str1,50,stdin);
    puts("enter str2:");
    fgets(str2,50,stdin);
    printf("%d",str_cmp(str1,str2));  
    return 0;
}
