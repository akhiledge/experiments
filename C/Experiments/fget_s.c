#include<stdio.h> 
#include<stdlib.h> 
int main(void) {
    char *st=NULL;
    st=(char *)malloc(sizeof(char)*10);
    fgets(st,5,stdin);
   if(*(st+1) < 95)
    printf("%s",st);
   return 0; 
}
