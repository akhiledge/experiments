/*this is quick__sort.c */
void quick__sort(int *a, int low, int high){/*quick sort*/ 
    int size=high;
    int pivot = low;/*to store the pivot element*/ 
    int i = low + 1, j = high;/*to traverse between elements of partition*/ 
    while(i <= j){  /*find the pivot element position*/ 
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
        else
            i++;
    }
    if(pivot < j){/*put the pivot element in it's final position*/ 
        swap((a + pivot), (a + j));
    }
    partition(a, low, high, j);/*partition array for further element sorting*/ 
}
