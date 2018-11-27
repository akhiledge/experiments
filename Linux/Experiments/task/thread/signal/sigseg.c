#include <stdio.h> 
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 

void hand(int sig_num){
    printf (" caught \n");
}
int main (void) {
    struct sigaction *myact = malloc(sizeof(struct sigaction));
    myact->sa_handler = hand;
    myact->sa_flags = SA_SIGINFO;
    sigaction(1, myact, NULL);
    sleep(2);
    raise(1);
    printf (" tata\n");
    free(myact); 
    return 0;
}
