#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <syscall.h>
    pthread_t myThread;
int hexprin(int *num){
    fork();
    static int i = 0;
    int j = 1;
    void *k;
    pthread_t myThread1;
    printf("t num %x %d\n",*num,syscall(SYS_gettid));
    ioctl(*num, 9, &j);
    while(i < 1){
        j = pthread_create(&myThread1, NULL, hexprin, num);
        printf("jj = %d %d\n",j ,syscall(SYS_gettid)); 
        i++;
    getchar();
    }
//    if(j != 0){
//        printf("no new thread %d\n", syscall(SYS_gettid)); 
//    }
//    else{
    if(0 == j){
        printf("thread created i = %d j = %d %d\n", i, j, syscall(SYS_gettid));
        pthread_join(myThread1, &k);
    }
    printf("tata  %d\n", syscall(SYS_gettid)); 
    getchar();
    return 0;
}
int main(int argc, char **argv) {
    int f;
    int p = 10;
    f = open(argv[1],O_RDWR);
    if(f < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",f);
    ioctl(f, 9, &p);
    pthread_create(&myThread, NULL, hexprin, &f);
    printf("tt %d\n",syscall(SYS_gettid)); 
    printf("new %d\n",p);
    getchar();
    wait(NULL);
    pthread_join(myThread, &p);
//    pthread_exit(&p);
    printf("tata %d\n", syscall(SYS_gettid)); 
    close(f);
    return 0;
}
