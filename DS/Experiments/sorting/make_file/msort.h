#ifndef _MSORT_H /*header guard for msort.h*/ 
#define _MSORT_H

void merge_sort(int *a, int low, int high);/*sorts array using quick sort*/ 
void swap(int *a, int *b);/*to swap the values */ 
void partition1(int *a, int low, int mid, int high);/*to make partition for 
                                                     further sorting*/ 
#endif /* msort.h included*/ 
