#include <time.h> 
#include <stdio.h>
#include <stdlib.h> 
int main (void) {
    time_t t, t2;
    time (&t);
    sleep (3);
    /*
    struct tm *today = calloc (1, sizeof (struct tm));
    struct tm *today1 = calloc (1, sizeof (struct tm));
    today = localtime (&t);
    printf (" %s \n", asctime (today)); 
    printf (" %s \n", ctime (&t)); 
    sleep (2);
    time (&t2);
    today = localtime (&t2);
    printf (" %s \n", asctime (today)); 
    printf (" %s \n", ctime (&t)); 
    printf (" %lf \n", difftime (t2, t));*/ 
    printf (" %lf \n", difftime (time (&t), t)); 
    return 0;
}
