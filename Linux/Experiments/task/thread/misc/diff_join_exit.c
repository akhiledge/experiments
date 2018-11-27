#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <syscall.h>
pthread_t myThread[3];
void *hexprin(void *a){
    printf (" in thread %d, %d\n", *((int *)a), syscall (SYS_gettid)); 
    if (*((int *)(a)) < 2){
        (*(int *)a == 0)?sleep (2):sleep (6);
        printf (" i woke up %d\n", *((int *)a)); 
    }
    else{
        sleep (5);
        printf (" i woke up %d\n", *((int *)a)); 
        pthread_exit (NULL);
    }
    printf (" in th   read %d, %d\n", *((int *)a), syscall (SYS_gettid)); 
    return NULL;
}
int main(int argc, char **argv) {
    int p1 = 0, p =1, p2 = 2;
    int ret;
    printf("main %d\n",syscall(SYS_gettid)); 
    sleep (2);
#if 0
    f = open(argv[1],O_RDWR);
    if(f < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",f);
    ioctl(f, 9, &p);
#endif
    ret = pthread_create(&myThread[0], NULL, hexprin, &p1);
    if ( ret < 0 )
        perror ("create thread 1 in main ");
    ret = pthread_detach(myThread[0]);
        perror ("detach thread 1 in main ");
    ret = pthread_create(&myThread[1], NULL, hexprin, &p);
    if ( ret < 0 )
        perror ("create thread 2 in main ");
    ret = pthread_detach(myThread[1]);
        perror ("detach thread 2 in main ");
    ret = pthread_create(&myThread[2], NULL, hexprin, &p2);
    if ( ret < 0 )
        perror ("create thread 3 in main ");
    ret = pthread_detach(myThread[2]);
        perror ("detach thread 3 in main ");
    sleep (15);
    printf("tata. %d\n", syscall(SYS_gettid)); 
  //  pthread_exit(&p);
    return 0;
}
