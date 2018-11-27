/****
 *distance between stations
 * */ 
#include "train.h"

int distance_btw_stn (const char *source, const char *dest, station *origin){
    int start = -1;//distance of source from origin
    int end = -1;//distance of dest from origin
    station *current = NULL;
    current = origin;
    if (CODE_SIZE < (strlen (source))){
        while (NULL != current){
            if (0 == strncasecmp (source, (current->stn_name), 8)){
                start = (current->dist);
                break;
            }
            current = current->next;
        }
    }
    else{
        while (NULL != current){
            if (0 == strncasecmp (source, (current->code), 3)){
                start = (current->dist);
                break;
            }
            current = current->next;
        }
    }
    current = origin;
    if (CODE_SIZE < (strlen (dest))){
        while (NULL != current){
            if (0 == strncasecmp (dest, (current->stn_name), 8)){
                end = (current->dist);
                break;
            }
            current = current->next;
        }
    }
    else{
        while (NULL != current){
            if (0 == strncasecmp (dest, (current->code), 3)){
                end = (current->dist);
                break;
            }
            current = current->next;
        }
    }
    current = NULL;
    if ((end == -1) || (start == -1))
        return -1;
    return (abs (end - start));
}
