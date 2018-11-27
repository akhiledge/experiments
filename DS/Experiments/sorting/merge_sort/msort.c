/*this is msort.c */ 
#include<stdlib.h> 
#include "msort.h"
void merge_sort(int *a, int low, int high){/*merge sort*/ 
    int mid;/*to store the pivot element*/ 
    mid = (low + high)/2;
    int i = low;
    int j = mid + 1;
    int k = low;
    static int *b = NULL;
    if(b == NULL){
        b = (int *)malloc(sizeof(int )*(high + 1));
    }
    partition(a, low, mid, high);
    while((i <= mid) && (j <= high)){
        if(*(a + i) > *(a + j)){
            *(b + k++) = *(a + j++);
            //j++;
        }
        else{
            *(b + k++) = *(a + i++);
            //i++;
        }
       // k++;
    }
    if(i <= mid){
        while(i <= mid){
            *(b + k++) = *(a + i++);
           // k++;
          //  i++;
        }
    }
    if(j <= high){
        while(j <= high){
            *(b + k++) = *(a + j++);
//            k++;
  //          j++;
        }
    }
    for(k = low; k<= high; k++){
        *(a + k) = *(b + k);
    }
}
void partition(int *a, int low, int mid,int high){
    if(low < mid)
        merge_sort(a, low, mid);
    if((mid + 1) < high)
        merge_sort(a, (mid + 1), high);
}
