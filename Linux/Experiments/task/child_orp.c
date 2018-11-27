#include<stdio.h>
#include<unistd.h> 
int main(void)
{
    int pid;
    pid = fork();
    if(pid > 0)
        printf("parent pid %d\n",getpid());
    else if(pid == 0)
        printf("child pid %d\n",getpid()); 
    else
        printf("no child\n"); 
    getchar();
    return 0;
}
