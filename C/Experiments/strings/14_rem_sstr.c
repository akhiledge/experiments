#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#define SIZE 75
char *rem_sstr(char *str, const char *sstr)
{
    int i=0,j=0,len;
    for(len=0;sstr[len]!='\0';len++);
    while(str[i]!='\0')
    {
        if(str[i]==sstr[0])
        {
            j=0;
            while(str[i+j]==sstr[j])
            {
                if(sstr[j+1]=='\0')
                {
                    j=0;
                    while(str[i+j+len]!='\0')
                    {
                        str[i+j]=str[i+j+len];
                        j++;
                    }
                    str[i+j]='\0';
                    i-=2;
                        break;
                }
             j++;       
            }
        }
        i++;
    }
    return str;
}
int main(void) 
{
    int i=0,len;
    char *str,*sstr;
    str=(char *)malloc(sizeof(char)*SIZE);
    sstr=(char *)malloc(sizeof(char)*SIZE);
    puts("Enter string:");
    fgets(str,SIZE,stdin);
    for(len=0;str[len]!='\0';len++);
    str[len-1]='\0';
    puts("enter substring:");
    fgets(sstr,SIZE,stdin);
    for(len=0;sstr[len]!='\0';len++);
    sstr[len-1]='\0';
    printf("%s\n",(rem_sstr(str,sstr)));
    return 0;
}
