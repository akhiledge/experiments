#include <stdio.h> 
#include <stdlib.h>
#include<unistd.h> 
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <syscall.h>
#include<string.h> 
#include <err.h>
 //   pthread_t myThread;

    static int i = 2;
static int s = 0;
//pthread_mutex_t myMutex = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void *print_nothing(void *k){
//    *i = (*i) + 2;
    int j ;
    j = pthread_mutex_lock (&myMutex);
    if( j == 0)
        printf("mutex locked\n");
    else{
       warn( "%s", strerror(j)); 
    }
    printf("\n in nothing i1 =%d in thread %ld\n", (i)+=2, syscall(SYS_gettid));
    printf("\n nothing i2 =%d in thread %ld\n", (i)+=2, syscall(SYS_gettid));
    printf("\n nothing i3 =%d in thread %ld\n", (i)+=2, syscall(SYS_gettid));
    j = pthread_mutex_unlock (&myMutex);
    if( j == 0)
        printf("mutex unlocked\n");
    else{
       warn( "%s", strerror(j)); 
    }
    return NULL;
}

int hexprin(int *num){
  //  fork();
      //  sleep(3);
    printf("\n\n"); 
    int j ;
    j = pthread_mutex_lock (&myMutex);
    if( j == 0)
        printf("mutex locked\n");
    else{
       warn( "%s", strerror(j)); 
    }
    pthread_t myThread1;
    printf("t num %x %ld\n",(*num)*25,syscall(SYS_gettid));
    ioctl(*num, 9, &j);
    while(i < 3){
        j = pthread_create(&myThread1, NULL, &print_nothing, NULL);
        if ( j == -1 ) 
            printf ( "\n thread err \n");
        printf("j(ret val of create) = %d i %d %ld\n",j ,i ,syscall(SYS_gettid)); 
        ++i;
//    getchar();
    }
//    if(j != 0){
//        printf("no new thread %d\n", syscall(SYS_gettid)); 
//    }
//    else{
    if(0 == j){
        printf("thread created i = %d j = %d %ld\n", i, j, syscall(SYS_gettid));
        printf("i1 = %d %ld\n",i ,syscall(SYS_gettid)); 
//        pthread_join(myThread1, &k);
        printf("j2 = %d %ld\n",j ,syscall(SYS_gettid)); 
//    pthread_exit(&j);
    }
/*    j = pthread_mutex_unlock (&myMutex);
    if( j == 0)
        printf("mutex unlocked\n"); 
    else{
       warn( "%s", strerror(j)); 
    }
    j = pthread_mutex_lock (&myMutex);
    if( j == 0)
        printf("mutex locked2\n"); 
    else
       warn( "%s", strerror(j));
      */ 
    s++;
    sleep(14);
        printf("s = %d %ld\n", s, syscall(SYS_gettid)); 
    printf("tata  %ld\n", syscall(SYS_gettid)); 
//    getchar();
        printf("i2 = %d %ld\n", ++i, syscall(SYS_gettid)); 
    j = pthread_mutex_unlock (&myMutex);
    if( j == 0)
        printf("mutex unlocked2\n"); 
    else{
       warn( "%s", strerror(j)); 
    }
    pthread_join (myThread1,(void*)( &s));
    return 0;
}

int main(int argc, char **argv) {
    int f;
    int p = 10;
    int ret = -1 ;
    pthread_t myThread;
    f = open(argv[1],O_RDWR);
    if(f < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",f);
    ioctl(f, 9, &p);
    ret = pthread_create(&myThread, NULL, &hexprin, &f);
    if ( ret < 0 )
       warn( "%s", strerror(ret)); 
    ret = pthread_detach(myThread);
    printf ( "\n ret = % d", ret );
    printf("tt %ld\n",syscall(SYS_gettid)); 
    printf("new %d\n",p);
//    sleep(188);
//    getchar();
   // wait(NULL);
//    pthread_join(myThread, &p);
    close(f);
    pthread_exit(&p);
    printf("tata. %ld\n", syscall(SYS_gettid)); 
    return 0;
}
