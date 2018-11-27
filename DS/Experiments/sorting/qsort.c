/*this is qsort.c */ 
#include<stdio.h> 
#include "qsort.h"
void sort(int *a, int low, int high){/*quick sort*/ 
    int pivot = low;/*to store the pivot element*/ 
    int i = low + 1, j = high;/*to traverse between elements of partition*/ 
    do{  /*find the pivot element position*/ 
        while((i <= high) && (*(a + i) < *(a + pivot))){
            i++;
        }
        while((j >= pivot) && (*(a + j) > *(a + pivot))){
            j--;
        }
        if(i < j){
            swap((a + i), (a + j));
            i++;
            j--;
        }
    }while(i < j);
    if(pivot < j){/*put the pivot element in it's final position*/ 
        swap((a + pivot), (a + j));
    }
    partition(a, low, high, j);/*partition array for further element sorting*/ 
}
void swap(int *a, int *b){/*swap the elements*/ 
    int t = *a;
    *a = *b;
    *b = t;
}
void partition(int *a, int low, int high, int j){/*partition the array based on
                                                   pivot element*/ 
    if(low < high){
        if(low != j)
            sort(a, low, j-1);
        if((j + 1) <= high)
            sort(a, j + 1, high);
    }
}
