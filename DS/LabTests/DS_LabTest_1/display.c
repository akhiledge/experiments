#include "train.h"
int display (station *origin){
     station *current = NULL;
     current = origin;
     while ( NULL != current ){
     printf ("%s", current->code);  
     printf (" %s", current->stn_name);  
     printf (" %.2d:", current->arrival.hr);  
     printf ("%.2d ", current->arrival.min);  
     printf (" %.2d:", current->departure.hr);  
     printf ("%.2d ", current->departure.min);  
     printf (" %.2d:", current->halt.hr);  
     printf ("%.2d ", current->halt.min);  
     printf (" %3d ", current->dist);  
     printf (" %.1d\n ", current->day); 
     current = current->next;
     }

     return 0;
}
