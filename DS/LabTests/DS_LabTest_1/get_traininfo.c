/**
 *
 *get_traininfo 
 * */
#include "train.h"
int get_traininfo (FILE *fp, station *origin)
{
    int i = 0;
    char *buf = malloc (sizeof (char) * NUM_BUF);
    station *current = NULL;
    
    current = origin;
    while ( (i++) < 8 ){
        current->code = malloc (sizeof (char) * CODE_SIZE);
        if (NULL == fgets ( (current->code), CODE_SIZE, fp ))
            warn ("code %s\n", strerror (0));

        current->stn_name= malloc (sizeof (char) * BUF_SIZE);
        if (NULL == fgets ( (current->stn_name), BUF_SIZE, fp ))
            warn ("code %s\n", strerror (0));

        current->arrival.hr = atoi (fgets (buf, NUM_BUF, fp));
        current->arrival.min = atoi (fgets (buf, NUM_BUF, fp));
    
        current->departure.hr = atoi (fgets (buf, NUM_BUF, fp));
        current->departure.min = atoi (fgets (buf, NUM_BUF, fp));
    
        current->halt.hr = 0;
        current->halt.min = atoi (fgets (buf, 3, fp));
    
        current->dist = atoi (fgets (buf, 5, fp));
        current->day = atoi (fgets (buf, 4, fp));

        if(i < 8){
            current->next = malloc (sizeof (station));
            current = current->next;
        }
        else
            current->next = NULL;
    }
//    current->next = NULL;
    return 1;
}
