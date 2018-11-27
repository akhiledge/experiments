/*this is main.c for selection sort*/ 
#include<stdio.h> 
#include "/home/vinay/b86_vk.vepuri/DS/Experiments/ato_i.h"/*my atoi function*/
#include "ssort.h"
#define BUF_SIZE 16/*buffer size*/ 
int main(void) 
{
    char *str = NULL;/*to store the input*/ 
    str = (char *)malloc(sizeof(char) * BUF_SIZE);
    int size_array;/*to store the size of array*/ 
    int i; /*to store index of array*/ 
    puts("Enter the number of elements you want to sort");
    size_array = ato_i(fgets(str, BUF_SIZE, stdin));
    int arr[size_array];/*variable size array to store elements to sort*/ 
    puts("Enter the elements to sort");
    for(i = 0; i < size_array; i++){/*storing elements into array*/ 
        *(arr + i) = ato_i(fgets(str, BUF_SIZE, stdin));
    }
    selection_sort(arr, 0, (size_array - 1));/*sorting elemnts using 
                                               selection sort*/ 
    puts("Elements after sorting");
    for(i = 0; i < size_array; i++){/*printing elements of array after sorting*/ 
        printf(" %d ", *(arr + i)); 
    }
    puts("");

    return 0;
}
