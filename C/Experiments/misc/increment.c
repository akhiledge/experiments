#include <stdio.h> 
#include <stdlib.h> 
int main (int arg_cnt, char **cmdArg) {
    printf (" \nafter incrementing %d\n", -(~(atoi (*(cmdArg + 1))))); 
    return 0;
}
