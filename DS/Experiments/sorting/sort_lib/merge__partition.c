/*!this is merge__partition.c 
 * @author : vinay
 * @date : 02-May-2018*/ 
void merge__partition(int *a, int low, int mid,int high){/*!
partition the array into two until it's size is greater than one.*/
    if(low < mid)
        merge__sort(a, low, mid);
    if((mid + 1) < high)
        merge__sort(a, (mid + 1), high);
}
