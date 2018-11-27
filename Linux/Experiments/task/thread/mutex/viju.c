#include <stdio.h> 
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <signal.h> 
pthread_t th;

    int st;
void *fun(void *k){
    printf ("in thread\n "); 
    st = pthread_detach(pthread_self());
//    st = pthread_detach(th);
    printf (" in thread st %d\n", st);
    sleep(3);
    printf (" bye bye \n");
    st = 7;
    printf (" in thread st %d\n", st);
    pthread_exit(&st); 
    return &st;
}

int main(void ){
    int st1;
    void *p;
    printf (" in main\n");
    pthread_create(&th, NULL, fun, NULL);
//    pthread_detach(th);
    //sleep(7);
    st1 = pthread_join(th, &p);
    printf (" in main st %d %s\n", st1, strerror(st1));
    printf (" in main ioit %d %s\n", st1, strerror(SIGIOT));
//    sleep(3);
    printf (" bye main %d\n", *((int *)p)); 
    return 0;
}
