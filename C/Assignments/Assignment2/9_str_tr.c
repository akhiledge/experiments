#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define SIZE 100
char *str_tok(const char *buf,const char *delim)
{
    int i=0;
    static int tr;
    static char *tok=NULL;
    if(tok==NULL)
        tok=(char *)malloc(sizeof(char)*SIZE);
    while(buf[tr]!='\0')
    {
        for(i=0;(buf[tr]!=*delim)&&(buf[tr]!='\0');i++,tr++)
        {
       // while()
            tok[i]=buf[tr];
        }
        break;
    }
    tok[i]='\0';
    if(buf[tr]!='\0')
    {
        tr++;
    }
    return tok;
}
rem_new_line(char *str)
{
    int len;
    for(len=0;str[len]!='\0';len++);
    str[len-1]='\0';
}
int main(void) 
{
    int len,i;
    char *buf=NULL,*delim=NULL,*token=NULL;
    delim=(char *)malloc(sizeof(char)*SIZE);
    buf=(char *)malloc(sizeof(char)*SIZE);
    token=(char *)malloc(sizeof(char)*SIZE);
    puts("enter string:");
    fgets(buf,SIZE,stdin);
    rem_new_line(buf);
    puts("enter delimiter:");
    fgets(delim,SIZE,stdin);
    rem_new_line(delim);
    token=str_tok(buf,delim);
    while(*token!='\0')
    {
        printf("%s\n",token);
        token=str_tok(buf,delim);
    }
    if(*token=='\0')
        puts(token);
    return 0;
}

