#include<stdio.h> 
#include<stdlib.h>
#define SIZE 75
size_t str_spn(const char *buf1,const char *buf2)
{
    int i=0,j=0,flag;
    while(*(buf1+i)!='\0')
    {
        j=0,flag=0;
        while(*(buf2+j)!='\0')
        {
            if(*(buf1+i)==*(buf2+j))
                flag=1;
            j++;
            if((*(buf2+j)=='\0')&&flag==0)
                return i;
        }
        i++;
    }
    return i;
}
rem_new_line(char *str)
{
    int len;
    for(len=0;*(str+len)!='\0';len++);
    *(str+len-1)='\0';
}
int main(void) 
{
    char *buf1=NULL,*buf2=NULL;
    buf1=(char *)malloc(sizeof(char)*SIZE);
    buf2=(char *)malloc(sizeof(char)*SIZE);
    puts("enter buf1:");
    fgets(buf1,SIZE,stdin);
    rem_new_line(buf1);
    puts("enter buf2:");
    fgets(buf2,SIZE,stdin);
    rem_new_line(buf2);
    printf("%d",str_spn(buf1,buf2));     
    return 0;
}

