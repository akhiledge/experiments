#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 
#define PARTS 4

static pthread_t th[4];
static int alphabet[27];
int size_file = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
FILE *fp = NULL;

void *file_size_part (void *arg){
    int part = *( (int *) arg);
    int status = 0;
    char ch = 0;
    int end = 0;
    
    status = pthread_mutex_lock (&lock);
    if (0 != status)
        warn ("%s\n", strerror (status));
    if ((PARTS - 1) != part)
        end = (size_file/PARTS) * (part + 1) ;
    else 
        end = size_file;
    
    rewind (fp);
    fseek(fp, ((size_file/4) * part), SEEK_SET);
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

int main (void) {

    int index = 0;
    int status ;
    int total = 0;
    fp = fopen ("text.c", "r");
    if (NULL == fp)
        printf (" file not opened"); 
    fseek (fp, 0, SEEK_END);
    size_file = ftell(fp);
    printf ("file size %d\n", size_file);
    rewind (fp);
    
    for (; index < PARTS; index++){
        create_thread(index);
    }

    //sleep(5);
    for (index = 0; index < 26; index++){
        total += (*(alphabet + index));
        printf (" \'%c\'-%-3d", (65 + index), *(alphabet + index) ); 
    }
    printf (" %s - %-3d\n", "symbols", *(alphabet + index ) ); 

    
    fclose (fp);
    fp = NULL;
    return 0;
}


