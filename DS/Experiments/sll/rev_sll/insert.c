#include "rev_sll_header.h"
int insert (int data){
    node *current = NULL;
    if (NULL == start){
        current = (node *) calloc (NMEMBER, sizeof (node));
        start = current;
    }
    else{
        current = start;
        while (NULL != (current->next)){
            current = current->next;
        }
        (current->next) = (node *) calloc (NMEMBER, sizeof (node));
        current = current->next;
    }
    length++;
    current->value = data;
    current->next = NULL;
    return 0;
}
