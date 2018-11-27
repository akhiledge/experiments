#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <mqueue.h> 
#include <err.h>
#include <string.h>

#define MAX_MSG 10
#define MSG_SIZE 8192
#define PARTS 4

static pthread_t th[4];
int size_file = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
FILE *fp = NULL;
FILE *fp_wr = NULL;
char *queue_name = NULL;

void *file_size_part (void *arg){
    int part = *( (int *) arg);
    int status = 0;
    char ch = 0;
    int end = 0;
    char *str = malloc (sizeof (char) * MSG_SIZE);
    mqd_t myDes;

    
    status = pthread_mutex_lock (&lock);
    if (0 != status)
        warn ("%s\n", strerror (status));
    if ((PARTS - 1) != part)
        end = (size_file/PARTS) * (part + 1) ;
    else 
        end = size_file;
    
    myDes = mq_open (queue_name, O_RDWR);
    mq_receive (myDes, str, MSG_SIZE, 0);
    if(part != PARTS - 1)
        fwrite (str, (size_file/PARTS), 1, fp_wr);
    else
        fwrite (str, (size_file/PARTS) + ((size_file%PARTS)), 1, fp_wr);
#if 0
    rewind (fp_wr);
    fseek(fp_wr, ((size_file/4) * part), SEEK_SET);
    ch = fgetc (fp);
    while ( (ftell (fp) < end + 1) && (EOF != ch)){
        if ( (ch >= 'A' && ch <= 'Z')){
            (*(alphabet + ch - 'A'))++;
        }
        else if ( (ch >= 'a' && ch <= 'z')){
            (*(alphabet + ch - 'a'))++;
        }
        else{
            (*(alphabet + 26))++;
        }
        ch = fgetc (fp);
    } 
#endif
    status = pthread_mutex_unlock (&lock);
    if (0 != status)
        warn ("%s\n", strerror (status));

    return NULL;
}
void *create_thread (int arg){
    int status ;
    status = pthread_create ( (th + arg), NULL, file_size_part, &arg);
    if (0 != status)
        warn ("%s\n", strerror (status));
    status = pthread_detach (th[arg]);
    if (0 != status)
        warn ("%s\n", strerror (status));
    sleep (1);
    return NULL;
}

int main (int argc, char **val) {
    printf (" argc %d %s %s ", argc, val[0], val[1]); 

    int index = 0;
    int status ;
    int total = 0;
    char *str = malloc (sizeof (char ) * MSG_SIZE);
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

    queue_name = malloc (sizeof (char ) * 50);
    int len = strlen ( *(val + 1));
    memcpy (queue_name, *(val + 1), len);
    fp_wr = fopen (*(val + 3), "w");
    if (NULL == fp_wr)
        printf (" file not opened"); 
    fp = fopen (val[2], "r");
    if (NULL == fp)
        printf (" file not opened"); 
    fseek (fp, 0, SEEK_END);
    size_file = ftell(fp);
    printf ("file size %d\n", size_file);
    rewind (fp);
    printf ( "\n size = %d \n",size_file/PARTS );

    for (; index < PARTS; index++){
        if ((PARTS - 1) != index) { 
        fread (str, (size_file/PARTS), 1, fp);
        printf (" strlen = %d sizeof = %d \n", strlen (str), sizeof (str)); 
            status = mq_send (myDes, str, (strlen (str) ), 0);
            //status = mq_send (myDes, str, ((size_file/PARTS) ), 0);
            if ( status < 0 )
                perror ( "failed ");

    }
        else {
        fread (str, ((size_file/PARTS) + (size_file%PARTS)), 1, fp);
            status = mq_send (myDes, str, ((size_file/PARTS) + (size_file%PARTS)), 0);
            if ( status < 0 )
                perror ( "failed ");
        }
        create_thread(index);
    }

    //sleep(10);
 /*   
    for (index = 0; index < 26; index++){
        total += (*(alphabet + index));
        printf (" \'%c\'-%-3d", (65 + index), *(alphabet + index) ); 
    }
    printf (" %s - %-3d\n", "symbols", *(alphabet + index ) ); 
*/
    
    mq_close (myDes);
    fclose (fp_wr);
    fp_wr = NULL;
    fclose (fp);
    fp = NULL;
    return 0;
}
