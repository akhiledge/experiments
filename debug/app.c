/**
 * File              : app.c
 * Author            : Vepuri Vinay Kumar <vk.vepuri@globaledgesoft.com>
 * Date              : 08.10.2018
 * Last Modified Date: 08.10.2018
 * Last Modified By  : Vepuri Vinay Kumar <vk.vepuri@globaledgesoft.com>
 */
#include<stdio.h> 
#include<stdlib.h>
#include<fcntl.h>
#include<sys/ioctl.h>
int main(int argc, char **argv) {
    /*./a.out /dev/re*/
   /*here re is the devname given while inserting module*/  
    int f;
    int *k = NULL;
    k = (int *)malloc(sizeof(int));
    *k = 8;
    int p = 10;
    /*argv[1] path to sudo device eg: /dev/re*/ 
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
