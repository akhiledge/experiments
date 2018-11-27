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
//    printf("%d %s %s ", cnt, val[0], val[1]);
    int status;
    char *str = malloc( sizeof( char) * MSG_SIZE);
    mqd_t myDes;

    myDes = mq_open( val[1], O_RDONLY);
    if(-1 == (int)myDes ){
        err( (int)myDes, "%s %d\n", strerror((int)myDes), (int)myDes);
    }
    else{
        warn( "%s %d\n", strerror((int)myDes), (int)myDes);
    }

    do{
        status = mq_receive(myDes, str, MSG_SIZE, 0);
        if(-1 == (int)status ){
            err( status, "%s %d\n", strerror(status), status);
        }
        else{
            *(str + strlen(str) + 1) = '\0';
            fputs(str, stdout);
        }
        if(0 == strncmp(str, "tata", 4)){
            break;
        }

    }while(1);

    status = mq_close(myDes);
    if(-1 == status ){
        err( status, "close %s\n", strerror(status));
    }
    else{
        warn( "close %s\n", strerror(status));
    }
     free(str);
     str = NULL;
     //free(myAttr);
     //myAttr = NULL;

    return 0;
}





