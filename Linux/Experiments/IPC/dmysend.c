#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <err.h>
#include <string.h>

#define MAX_MSG 32
#define MSG_SIZE 512

int main (int cnt, char **val) {
//    printf ("%d %s %s ", cnt, val[0], val[1]); 
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

    do{
        fgets( str, MSG_SIZE, stdin);
        status = mq_send(myDes, str, strlen(str), 0);
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

    }while(1);

    status = mq_close(myDes);
    if(-1 == status ){
        warn( " close %s\n", strerror(status));
    }
    else{
        warn( "close %s\n", strerror(status));
    }
     free(str);
     str = NULL;

    return 0;
}





