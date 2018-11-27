#include<stdio.h> 
#include<pthread.h>
int fun(void *k ){
    static int i =0;
    pthread_t t1;
    int a =-1;
    while( 1 ){
        a = pthread_create( &t1, NULL, fun, NULL);
        i++;
        printf ("thread %d\n ", i);
        if( a != 0)
            err(a, NULL);
    }
    return 0;
}

int main(void) {
    pthread_t mt;
    int p = -1;
    p = pthread_create ( &mt, NULL, fun, NULL);
    if(p != 0)
        err(p, NULL);
    pthread_exit(NULL);
    return 0;

}
