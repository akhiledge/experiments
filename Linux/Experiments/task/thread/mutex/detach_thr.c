#include <stdio.h> 
#include <unistd.h>
#include <pthread.h>
#include <err.h>
#include <string.h> 
#include <sys/syscall.h>

pthread_t th1, th2;
pthread_mutex_t myLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t myLock1 = PTHREAD_MUTEX_INITIALIZER;
static int st_num = 0 ;

void *my_fun1(void *k){
        printf (" in thread %ld\n", syscall(SYS_gettid)); 
}
void *my_fun(void *k){
    int status;
#if 0
    status = pthread_mutex_lock(&myLock1);
    if(status != 0)
        warn( "%s", strerror(status));
    else{
        printf ("%s\n", strerror(status));
        warn( "%s", strerror(status));
        printf ("  locked in thread %ld\n", syscall(SYS_gettid)); 
    }
#endif
    status = pthread_detach(th1);
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf (" thread detached %ld\n", syscall(SYS_gettid)); 
    printf("tata thread %ld\n", syscall(SYS_gettid));
    sleep(5);
    if(st_num < 1){
    status = pthread_create(&th2, NULL, my_fun1, NULL);
    status = pthread_detach(th2);
    st_num++;
    }
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf (" thread created %ld\n", syscall(SYS_gettid)); 
    sleep(5);
#if 0
    status = pthread_mutex_unlock(&myLock1);
    if(status != 0)
        warn( "%s", strerror(status));
    else
        printf ("  unlocked in thread %ld\n", syscall(SYS_gettid)); 
#endif
    printf("tata1 thread %ld\n", syscall(SYS_gettid));
    return NULL;
}

int main (void) {
    int status;
    void *p;
    status = pthread_mutex_lock(&myLock);
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf ("  locked in main %ld\n", syscall(SYS_gettid)); 
    status = pthread_create(&th1, NULL, my_fun, NULL);
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf (" thread created %ld\n", syscall(SYS_gettid)); 
#if 0
    status = pthread_detach(th1);
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf (" thread detached %ld\n", syscall(SYS_gettid)); 
#endif
    status = pthread_join(th1, &p);
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf (" thread join %d %ld\n", status, syscall(SYS_gettid)); 
    status = pthread_mutex_unlock(&myLock);
    if(status != 0)
        warn( "%s\n", strerror(status));
    else
        printf ("  unlocked in main %ld\n", syscall(SYS_gettid)); 
    printf (" in main %ld\n", syscall(SYS_gettid)); 
    printf (" tata main %ld\n", syscall(SYS_gettid)); 
getchar();
    return 0;
}
