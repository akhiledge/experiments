#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define SIZE 75
int str_rot(const char *str,const char *rstr)
{
    int i=0,j=0,len;
    for(len=0;str[len]!='\0';len++);
    char *temp=(char *)malloc(sizeof(char)*2*SIZE);
    sappend(temp,rstr,rstr);
    while(temp[i]!='\0')
    {
        if(temp[i]==str[0])
        {
            j=0;
            while(temp[i+j]==str[j])
            {
                if(str[j+1]=='\0')
                    return 1;
                j++;
            }
        }
        i++;
    }
    return 0;
}

sappend(char *temp,char *str1,char *str2)
{
    int i=0,j=0;
    while(str1[i]!='\0')
    {
        temp[i]=str1[i];
        i++;
    }
    while(str2[j]!='\0')
    {
        temp[i]=str2[j];
        i++,j++;
    }
    temp[i]='\0';
}
int main(void)
{
    int len,flag=1;
    char *str=NULL,*rstr=NULL;
    str=(char *)malloc(sizeof(char)*SIZE);
    rstr=(char *)malloc(sizeof(char)*SIZE);
    puts("enter string:");
    fgets(str,SIZE,stdin);
    for(len=0;str[len]!='\0';len++);
    str[len-1]='\0';
    puts("enter rstring:");
    fgets(rstr,SIZE,stdin);
    for(len=0;rstr[len]!='\0';len++);
    rstr[len-1]='\0';
    flag=str_rot(str,rstr);
    printf("'%s' is %srotated string of '%s'\n",rstr,(flag==0)?"not ":"",str);
    return 0; 
}
