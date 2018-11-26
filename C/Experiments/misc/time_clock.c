#include <stdio.h> 
#include <sys/times.h> 
#include <time.h> 
int main (int arg_cnt, char **cmdArg) {
    clock_t t2 = clock ();
    struct tms buf;
    int i = 0;
    while (i < 1000000000)
        i++;
    times (&buf);
    clock_t t1 = clock ();
    printf (" %ld \n", (buf.tms_utime)); 
    printf (" %ld \n", (buf.tms_stime)); 
    printf (" %ld \n", (buf.tms_cutime)); 
    printf (" %ld \n", (buf.tms_cstime)); 
    printf (" %ld %ld %ld \n", t2, t1, (t1 - t2)/CLOCKS_PER_SEC);
    printf (" %ld", CLOCKS_PER_SEC); 
    return 0;
}
