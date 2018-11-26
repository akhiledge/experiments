#include <stdio.h> 
#include <stdlib.h> 
int main (int arg_cnt, char **cmdArg)
{
    printf ("pid %d \n", getpid()); 
    char *str = malloc (4);

    getchar ();
    free (str);
    return 0;
}

