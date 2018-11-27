#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <err.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h> 

#define MAX_MSG 32
#define MSG_SIZE 512
pthread_mutex_t myLock = PTHREAD_MUTEX_INITIALIZER;
pthread_t th;

void *receive(void *arg){

    int status;
    char *c_arg = NULL;
    char *str = malloc(sizeof( char ) * MSG_SIZE);
    mqd_t myDes;
    c_arg = (char *)arg;
    sleep(3);
    myDes = mq_open( c_arg, O_RDWR);
    if(-1 == (int)myDes ){
        err( (int)myDes, "q1open %s %d\n", strerror((int)myDes), (int)myDes);
    }
    else{
        warn( "open %s %d\n", strerror((int)myDes), (int)myDes);
    }

   do{
       status = mq_receive(myDes, str, MSG_SIZE, 0);
//       pthread_mutex_lock(&myLock);

       if(-1 == (int)status ){
           err( status, "%s %d\n", strerror(status), status);
       }
       else{
           //*(str + strlen(str) + 1) = '\0';
           //fputs(str, stdout);
           puts(str);
       }
       if(0 == strncmp(str, "tata", 4)){
           break;
       }
//       pthread_mutex_unlock(&myLock);
 
   }while(1);


    status = mq_close(myDes);
    if(-1 == status )
        warn( " close %s\n", strerror(status));
    else
        warn( "close %s\n", strerror(status));
    free(str);
    str = NULL;
    return NULL;
}
int main (int cnt, char **val) {
    printf ("%d %s %s ", cnt, val[0], val[1]); 
    int i;
    int status;
    char *str = malloc( sizeof( char) * MSG_SIZE);
    mqd_t myDes;
    struct mq_attr myAttr;
    myAttr.mq_flags = 0;
    myAttr.mq_maxmsg = MAX_MSG;
    myAttr.mq_msgsize = MSG_SIZE;
    myAttr.mq_curmsgs = 0;

    myDes = mq_open( val[1], O_CREAT | O_RDWR, 0666, &myAttr);
    if(-1 == (int)myDes ){
        err( (int)myDes, "qopen %s %d\n", strerror((int)myDes), (int)myDes);
    }
    else{
        warn( "open %s %d\n", strerror((int)myDes), (int)myDes);
    }

    pthread_create(&th, NULL, &receive, val[1]);
    pthread_detach(th);
    do{
//        pthread_mutex_lock(&myLock);
        __fpurge(stdin);
        fgets( str, MSG_SIZE, stdin);
        status = mq_send(myDes, str, (strlen(str) + 1), 0);
#if 0
        if(-1 == status ){
            err( status, " msend %s %d\n", strerror(status), status);
        }
        else{
            warn( "msend %s\n", strerror(status));
        }
#endif
        if( 0 == strncmp(str, "tata", 4)){
            break;
        }
//        pthread_mutex_unlock(&myLock);

    }while(1);

    status = mq_close(myDes);
    if(-1 == status )
        warn( " close %s\n", strerror(status));
    else
        warn( "close %s\n", strerror(status));
     free(str);
     str = NULL;
    

    pthread_exit(&status); 
    return 0;
}





