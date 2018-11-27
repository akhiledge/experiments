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

static int st_num = 2;
static pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void *print_inc_2(void *k){
    printf (" in thread %ld\n", syscall(SYS_gettid)); 
    int ret_val ;
//    ret_val = pthread_mutex_lock (&myMutex);
    if( ret_val == 0)
        printf("mutex locked\n");
    else{
       warn( "%s", strerror(ret_val)); 
    }
    printf("\n st_num =%d in thread %ld\n", (st_num)+=2, syscall(SYS_gettid));
    printf("\n st_num =%d in thread %ld\n", (st_num)+=2, syscall(SYS_gettid));
    printf("\n st_num =%d in thread %ld\n", (st_num)+=2, syscall(SYS_gettid));
  //  ret_val = pthread_mutex_unlock (&myMutex);
    if( ret_val == 0)
        printf("mutex unlocked\n");
    else{
       warn( "%s", strerror(ret_val)); 
    }
}

int hexprin(int *num){
    printf ("\n\n in thread %ld\n", syscall(SYS_gettid)); 
  //  fork();
      //  sleep(3);
    int ret_val ;
    ret_val = pthread_mutex_lock (&myMutex);
    if( ret_val == 0)
        printf("mutex locked\n");
    else{
       warn( "%s", strerror(ret_val)); 
    }
    pthread_t myThread1;
    printf("num*25 in hex %x %ld\n",(*num)*25,syscall(SYS_gettid));
    ioctl(*num, 9, &ret_val);
    while(st_num < 3){
        ret_val = pthread_create(&myThread1, NULL, &print_inc_2, NULL);
        if ( ret_val == -1 ) 
            printf ( "\n thread err \n");
        printf("ret_val = %d st_num %d %ld\n", ret_val, st_num, syscall(SYS_gettid)); 
        ++st_num;
//    getchar();
    }
    if(0 == ret_val){
        printf("thread created st_num = %d ret_val = %d %ld\n", st_num, ret_val, syscall(SYS_gettid));
        printf("st_num1 = %d %ld\n", st_num, syscall(SYS_gettid)); 
        printf("ret_val2 = %d %ld\n", ret_val, syscall(SYS_gettid)); 
//    pthread_exit(&ret_val);
    }
    sleep(14);
//    getchar();
        printf("st_num2 = %d %ld\n", ++st_num, syscall(SYS_gettid)); 
    ret_val = pthread_mutex_unlock (&myMutex);
    if( ret_val == 0)
        printf("mutex unlocked\n"); 
    else{
       warn( "%s", strerror(ret_val)); 
    }
    pthread_join (myThread1, (void **)(&ret_val));
    printf("tata hexprint  %ld\n", syscall(SYS_gettid)); 
    return 0;
}

int main(int argc, char **argv) {
    int fd_mod;
    int num1 = 10;
    int ret_val = -1 ;
    pthread_t myThread;
#if 1
    fd_mod = open(argv[1],O_RDWR);
    if(fd_mod < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",fd_mod);
    ioctl(fd_mod, 9, &num1);
#endif
    ret_val = pthread_create(&myThread, NULL, &hexprin, &fd_mod);
    if ( ret_val < 0 )
       warn( "%s", strerror(ret_val)); 
    ret_val = pthread_detach(myThread);
    if( ret_val == 0)
        printf("thread detached \n"); 
    else{
       warn( "%s", strerror(ret_val)); 
    }
//    sleep(188);
//    getchar();
   // wait(NULL);
//    pthread_join(myThread, &p);
    close(fd_mod);
    pthread_exit(&num1);
    printf("tata_main %ld\n", syscall(SYS_gettid)); 
    return 0;
}
