/*this is ssort.c */ 
#include<stdlib.h> 
#include "ssort.h"
void selection_sort(int *a, int low, int high){/*selection sort*/ 
    int i;
    int j;
    int lowest_element_pos;
    for(i = low; i < high; i++){
        for(lowest_element_pos = i, j = i + 1; j <= high; j++){
            if(*(a + j) < *(a + lowest_element_pos)){
                lowest_element_pos = j;
            }
        }
        if(lowest_element_pos != i)
            swap((a + i), (a + lowest_element_pos));
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
