/*! 
 * \author vinay
 * \brief this is qsort header file*/ 
#ifndef _QSORT_H /*header guard for qsort.h*/ 
#define _QSORT_H

void quick__sort(int *a, int low, int high);/*\brief sorts array using quick sort*/ 
void swap(int *a, int *b);/*\brief to swap the values */ 
void quick__partition(int *a, int low, int high, int j);/*\brief to partition
                                                          for further sorting*/ 
#endif /* qsort.h included*/ 
