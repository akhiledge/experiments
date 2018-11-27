#include "rev_sll_header.h"
int display (int data){
    node *current = NULL;
    if (NULL == start){
        fputs ("list is empty\n", stdout);
        return -1;
    }
    current = start;
    while (NULL != current){
        printf (" %d", current->value); 
        current = current->next;
    }
    fputs ("\n", stdout);
    return 0;
}
