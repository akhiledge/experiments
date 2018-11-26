#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#define BUF_SIZE 16
int mul (int x, int y){
    if (y < 0){
        x = -x;
        y = -y;
    }
    if ((y >> 1) > 0){
        x = mul (x << 1, y >> 1) + ((y & 1) ? x : 0);
    }
    return x;
}
int main (int arg_cnt, char **cmdArg) {
    char *str = NULL;
    int x = 0;
    int y = 0;
    str = calloc (1, sizeof (char) * BUF_SIZE);
    fputs ("enter number 1", stdout);
    x = atoi (fgets (str, BUF_SIZE, stdin));
    memset (str, 0, BUF_SIZE);
    fputs ("enter number 2", stdout);
    y = atoi (fgets (str, BUF_SIZE, stdin));
    printf ("result %d \n", mul (x, y)); 
    return 0;
}
