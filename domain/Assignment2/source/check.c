#include <stdio.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <errno.h> 
#include <unistd.h> 

int main (int arg_cnt, char **cmdArg)
{
    int fd;
    int num = 12;
    fd = open (cmdArg[1], O_RDWR);
    while (1){
        printf (" number:"); 
        scanf ("%d", &num);
        num = ioctl (fd, num, &num);
        perror ("ioctl");
        printf ("ret = %d\n ", num);
    }
    close (fd);
    return 0; 
}
