#include<stdio.h> 
#include<stdlib.h>
#include<fcntl.h>
#include<sys/ioctl.h>
int main(int argc, char **argv) {
    fork();
    wait(NULL);
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
    printf("new %d",p);
    getchar(); 
    free(k);
    k = NULL;
    close(f);
    return 0;
}
