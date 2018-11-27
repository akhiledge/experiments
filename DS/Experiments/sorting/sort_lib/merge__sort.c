/*!this is merge__sort.c 
 * @author  vinay
 * @date 02-May-2018*/
#include<stdlib.h>   
void merge__sort(int *a, int low, int high){/*!sorts the array using 
                                              merge sort*/ 
    int mid;/*!to store the pivot position*/ 
    mid = (low + high)/2;
    int i = low;/*!index for first partition */
    int j = mid + 1;/*!index for second partition*/
    int k = low;/*!index for final sorted array*/
    int *b = NULL;/*!final sorted array*/
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
