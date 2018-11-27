#ifndef _QSORT_H /*header guard for qsort.h*/ 
#define _QSORT_H

void sort(int *a, int low, int high);/*sorts array using quick sort*/ 
void swap(int *a, int *b);/*to swap the values */ 
void partition(int *a, int low, int high, int j);/*to partition for further sorting*/ 
#endif /* qsort.h included*/ 