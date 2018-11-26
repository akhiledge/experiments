#include<stdio.h> 
#include<stdlib.h> 
#include<mcheck.h> 
int main(void) {
    mtrace();
    char *str = malloc(sizeof(char ) * 23);
    char *pp = malloc(sizeof(char )* 66);
    str = pp;
//    free(pp);
//    free(str);
    return 0;
}
