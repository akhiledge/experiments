#include<stdio.h>
#include<stdlib.h> 
int main(void)
{
    char **da=NULL;
    da=malloc(sizeof(char *)*2);
    *da=malloc(sizeof(char )*2);
    *(da+1)=malloc(sizeof(char )*2);
    *(da+2)=malloc(sizeof(char )*2);
    **da='d';
    *(*(da+1)+1)='g';
    printf("%p %p %p %c\n",&da,da,*da,**da); 
    printf("%p %p %p %p\n",*da,*(da+1),*(da+2),*(da+3)); 
    printf("%c %c\n",**da,*(*(da+1)+1)); 
    printf("%p %p %p %c\n",(&da)+1,(da)+1,(*da)+1,(**da)+1);
    free(*(da));
    free(da);
}
