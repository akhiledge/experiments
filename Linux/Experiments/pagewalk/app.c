#include<stdio.h> 
#include<fcntl.h>
#include<sys/ioctl.h>
int main(int argc, char **argv) {
    int f;
    int p = 10;
    f = open(argv[1],O_RDWR);
    if(f < 0)
        perror("unable to open device\n");
    else
        printf("file opened successfully %d\n",f);
    ioctl(f, 9, &p);
    printf("new %d",p);
    getchar(); 
    close(f);
    return 0;
}
