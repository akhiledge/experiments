/****
 *distance between stations
 * */ 
#include "train.h"

int time_btw_stn (char *source, char *dest, station *origin){
    int start = -1;//distance of source from origin
    int end = -1;//distance of dest from origin
    station *current = NULL;
    current = origin;
    if (CODE_SIZE < (strlen (source))){
        while (NULL != current){
            if (0 == strncasecmp (source, (current->stn_name), 8)){
                start = (current->arrival.min);
                start += ( (current->arrival.hr) * HR_TO_MIN);
                start += ( ( (current->day) - 1) == 1 ? DAY_TO_MIN : 0);
                break;
            }
            current = current->next;
        }
            current = origin;
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
            if (0 == strncasecmp (source, (current->code), 3)){
                start = (current->arrival.min);
                start += ( (current->arrival.hr) * HR_TO_MIN);
                start += ( ( (current->day) - 1) == 1 ? DAY_TO_MIN : 0);
                break;
            }
            current = current->next;
        }
            current = origin;
        while (NULL != current){
            if (0 == strncasecmp (dest, (current->code), 3)){
                end = (current->arrival.min);
                end += ( (current->arrival.hr) * HR_TO_MIN);
                end += ( ( (current->day) - 1) == 1 ? DAY_TO_MIN : 0);
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
