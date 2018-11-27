/*this is quick__partition.c */ 
void partition(int *a, int low, int high, int j){/*partition the array based on
                                                   pivot element*/ 
    if(low < high){
        if(low != j)
            quick__sort(a, low, j-1);
        if((j + 1) <= high)
            quick__sort(a, j + 1, high);
    }
}
