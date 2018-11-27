/*!
 *\brief This is merge sort header
 * \author viany
 * \date 02-May-2018*/
#ifndef _MSORT_H /*header guard for msort.h*/ 
#define _MSORT_H

/*!\brief sorts array using quick sort
\param *a,low,high takes pointer to array, starting index, ending index of partition
*/ 
void merge__sort(int *a, int low, int high);
/*!\brief to swap the values 
\param *a, *b takes pointers to the values to be swaped*/ 
void swap(int *a, int *b); 
/*!\brief to make partition
for further sorting
\param *a,low,mid,high takes pointer to array, starting index, pivot position, ending index*/ 
void merge__partition(int *a, int low, int mid, int high);
#endif /* msort.h included*/ 
