#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define SIZE 75
#define SWAP(a,b) (a^=b^=a^=b)
char *insertchar(char *str,const char ch,int pos)
{
    char t1;
    t1=ch;
    if(pos<strlen(str)){
    while(str[pos]!='\0')
    {
        SWAP(t1,(str[pos]));
        pos++;
    }
    str[pos]=t1;
    str[pos+1]='\0';
    }else
        printf("\npos is not string\n"); 
    return str;

}
int main(void) 
{
    char *str=(char *)malloc(sizeof(char)*SIZE),ch;
    int pos,i;
    puts("enter string:");
    fgets(str,SIZE,stdin);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='\n')
        {
            str[i]='\0';
            i--;
        }
    }
    puts("enter ch:");
    scanf("%c",&ch);
    puts("enter pos:");
    scanf("%d",&pos);
    str=insertchar(str,ch,pos);
    printf("\n%s\n",str);
    return 0;
}
