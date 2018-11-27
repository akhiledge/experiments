/*this is isort.c */ 
#include<stdio.h> 
#include "isort.h"
void insertion_sort(int *a, int low, int high){/*insertion sort*/ 
    int pivot = low + 1;/*to store the pivot element*/ 
    int i,k;/*to traverse between elements of partition*/ 
    do{  /**/ 
        i = pivot;
        while(i > 0){
            if((*(a + i)) < (*(a + i - 1))){
                swap((a + i), (a + i - 1));
            }
            else{
                break;
            }
            i--;
        }
        pivot++;
    }while(pivot <= high);
}
void swap(int *a, int *b){/*swap the elements*/ 
    int t = *a;
    *a = *b;
    *b = t;
}
