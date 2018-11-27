#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
int hexprin(int *num){
    printf("t num %x \n",*num);
    ioctl(*num, 9, &num);
    getchar();
    printf("num %d\n", *num); 
    return 0;
}
int main(int argc, char **argv) {
    pthread_t myThread;
    int f;
    int *k = NULL;
    k = (int *)malloc(sizeof(int));
    *k = 8;
    int p = 10;
    f = open(argv[1],O_RDWR);
    if(f < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",f);
    ioctl(f, 9, &p);
    pthread_create(&myThread, NULL, hexprin, &f);
    printf("new %d",p);
    getchar();
    pthread_exit(&p);
    free(k);
    k = NULL;
    close(f);
    return 0;
}
