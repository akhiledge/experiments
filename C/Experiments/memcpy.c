#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
int main (int arg_cnt, char **cmdArg) {
    char *str1 = malloc (12);
    fgets (str1, 12, stdin);
    //memcpy (str1, str1+2, 4);
    memmove (str1, str1+2, 4);
    fputs(str1, stdout);
    return 0;
}

