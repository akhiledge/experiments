/****
 *time from origin
 * */ 
#include "train.h"

int time_frm_origin (station *origin, char *source, char *dest){
    int start = -1;//time of source from origin
    int end = -1;//time of dest from origin
    station *current = NULL;
    current = origin;
    
    start = (current->arrival.min);
    start += ( (current->arrival.hr) * HR_TO_MIN);
    start += ( ( (current->day) - 1) == 1 ? DAY_TO_MIN : 0);

    if (CODE_SIZE < (strlen (dest))){
         while (NULL != current){
             if (0 == strncasecmp (dest, (current->stn_name), 8)){
                 end = (current->arrival.min);
                 end += ( (current->arrival.hr) * HR_TO_MIN);
                 end += ( ( (current->day) - 1) == 1 ? DAY_TO_MIN : 0);
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
    if ((-1 == start) || (-1 == end)){
        return -1;
    }
    return (abs (start - end));
}
