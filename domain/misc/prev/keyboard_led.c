#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdbool.h> 
#define BUF_SIZE 16

int main (void) {
    int fd = open ("/sys/class/leds/input2::capslock/brightness", O_WRONLY);

    if (-1 == fd){
        printf ("open failed \n ");
        return 0; 
    }
    int fd_ide = open ("/sys/class/leds/input2::capslock/trigger", O_WRONLY);

    if (-1 == fd_ide){
        printf ("open failed \n ");
        return 0; 
    }

    char *act = " disk-activity";
    write (fd_ide, act, 14);

    char *user_input = calloc (1, sizeof (char)*BUF_SIZE);
    while (true){
        lseek (fd, 0, SEEK_SET);
        fputs ("off-0 on-1 exit-4\n", stdout);
        fgets (user_input, BUF_SIZE, stdin);

        if (atoi (user_input)==4){
            free (user_input);
            user_input = NULL;
            return 0;
        }
        char *input = (atoi (user_input) == 1?"1":"0");
        if (-1 == write (fd, input, 1)){
            printf (" write failed \n"); 
        }
    }

    printf (" completed\n"); 
    free (user_input);
    user_input = NULL;
    close (fd);
    close (fd_ide);
    return 0; 
}
