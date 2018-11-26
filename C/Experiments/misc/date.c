/**********
 * print date in dd-mm-yyyy format
 *
 * if macro BUF_SIZE is not defined while compiling 
 * give date as command line argument in the format ddmmyyyy (string)
 *
 * if macro is defined at compile time (use -D BUF_SIZE=value 
 * where value is an integer, to define macro at compile time)
 * enter date at run time in the format dd-mm-yyyy (string) 
 ***********/ 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
//#define BUF_SIZE  
#ifndef BUF_SIZE 
int date (int today){
    return (today/1000000);
}
int month (int today){
    return ((today/10000)%100);
}
int year (int today){
    return (today%10000);
}
#endif
#ifdef BUF_SIZE 
unsigned int date (unsigned int today){
    return ((today & (0x0000001f)));
}
unsigned int month (unsigned int today){
    return ((today >> 5) & (0x0000000f));
}
unsigned int year (unsigned int today){
    return ((today >> 9) & (0x007fffff));
}
#endif
int main (int arg_cnt, char **cmdArg) {
#ifndef BUF_SIZE 
    int today = atoi (cmdArg[1]);
#endif
#ifdef BUF_SIZE 
    char *str = NULL;
    unsigned int today = 0;
    str = (char *) calloc (1, sizeof (char) * BUF_SIZE);
    fputs ("enter date ", stdout);
    fgets (str, BUF_SIZE, stdin);
    today = atoi (strtok (str, "-"));
    today = today | ((atoi (strtok (NULL, "-"))) << 5);
    today = today | ((atoi (strtok (NULL, "-"))) << 9);
    memset (str, 0, BUF_SIZE);
    free (str);
    str = NULL;
#endif
    printf (" date is %.2u-", date (today)); 
    printf ("%.2u-", month (today)); 
    printf ("%.4u \n", year (today)); 
    return 0;
}
