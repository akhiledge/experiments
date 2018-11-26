#include<stdio.h> 
#include<stdlib.h> 
char * str_cpy(char *buf,char c)
{
    int i;
    for(i=0;buf[i]!='\0';i++)
    {
        if(buf[i]==c)
            return &buf[i];
    }
    return NULL;
}
int main(void)
{
    char *buf,c;
    buf = (char *)malloc(sizeof(char)*50);
    printf("enter string:"); 
    fgets(buf,50,stdin);
    printf("enter character :");
    scanf("%c",&c);
    printf("The address of %c in %s is %p",c,buf,str_cpy(buf,c));
    return 0;

}
