#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <syscall.h>
 //   pthread_t myThread;
int hexprin(int *num){
  //  fork();
      //  sleep(3);
    static int i = 2;
    int j ;
    static int s = 0;
    void *k;
    pthread_t myThread1;
    printf("t num %x %d\n",*num,syscall(SYS_gettid));
    ioctl(*num, 9, &j);
    while(i < 3){
        j = pthread_create(&myThread1, NULL, hexprin, num);
        if ( j == -1 ) 
            printf ( "\n thread err \n");
        printf("j = %d i %d %d\n",j ,i ,syscall(SYS_gettid)); 
        i++;
//    getchar();
    }
//    if(j != 0){
//        printf("no new thread %d\n", syscall(SYS_gettid)); 
//    }
//    else{
    if(0 == j){
        printf("thread created i = %d j = %d %d\n", i, j, syscall(SYS_gettid));
        printf("i1 = %d %d\n",i ,syscall(SYS_gettid)); 
//        pthread_join(myThread1, &k);
        printf("j2 = %d %d\n",j ,syscall(SYS_gettid)); 
//    pthread_exit(&j);
    }
    s++;
    sleep(4);
        printf("s = %d %d\n",s ,syscall(SYS_gettid)); 
    printf("tata  %d\n", syscall(SYS_gettid)); 
//    getchar();
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
    ret = pthread_create(&myThread, NULL, hexprin, &f);
    if ( ret < 0 )
    printf ("\n THreqa kfj\n");
    ret = pthread_detach(myThread);
    printf ( "\n ret = % d", ret );
    printf("tt %d\n",syscall(SYS_gettid)); 
    printf("new %d\n",p);
//    sleep(188);
//    getchar();
   // wait(NULL);
//    pthread_join(myThread, &p);
    printf("tata. %d\n", syscall(SYS_gettid)); 
    close(f);
  //  pthread_exit(&p);
    return 0;
}
