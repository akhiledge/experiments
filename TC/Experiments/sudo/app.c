#include<stdio.h> 
#include<fcntl.h>
#include<sys/ioctl.h>
int main(int argc, char **argv) {
    int f;
    f = open(argv[1],O_RDWR);
    if(f < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",f);
    ioctl(f, 9, 7);
    getchar(); 
    close(f);
    return 0;
}
