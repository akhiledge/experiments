/***
 * \file main.c file contains main()
 * \author vinay
 * \date 02-May-2018
 * \brief sorts elements of an array using quick sort
 *******/
/***
 * \headerfile  stdio.h 
 * ***/

#include<stdio.h>
                 
 /****
  * \headerfile /home/vinay/b86_vk.vepuri/DS/Experiments/ato_i.h
  * ****/
 
#include "/home/vinay/b86_vk.vepuri/DS/Experiments/ato_i.h"
/*! \def BUF_SIZE 
 \brief buffersize*/ 
#define BUF_SIZE 16  
#include "/home/vinay/b86_vk.vepuri/DS/Experiments/sorting/sort_lib/qsort.h"
#include "/home/vinay/b86_vk.vepuri/DS/Experiments/sorting/sort_lib/msort.h"
/***\headerfile ""
 */
/*\fn int main(void)
 * \brief main function  for sorting*/ 
int main(void) 
{
    /*! \brief main function*/ 
    char *str = NULL;/**** \var str 
                       \brief to store the input*/ 
    str = (char *)malloc(sizeof(char) * BUF_SIZE);
    int size_array;/*!to store the size of array*/ 
    int i; /*!to store index of array*/ 
    puts("Enter the number of elements you want to sort");
    size_array = ato_i(fgets(str, BUF_SIZE, stdin));
    int arr[size_array];/*!variable size arrayb to store elements to sort*/ 
    puts("Enter the elements to sort");
    for(i = 0; i < size_array; i++){/*!storing elements into array*/ 
        *(arr + i) = ato_i(fgets(str, BUF_SIZE, stdin));
    }
    quick__sort(arr, 0, (size_array - 1));/*!sorting elemnts using quick sort*/ 
    puts("Elements after sorting");
    for(i = 0; i < size_array; i++){/*! printing elements of array after sorting*/ 
        printf(" %d ", *(arr + i)); 
    }
    puts("");
    free(str);
    str = NULL;
    return 0;
}
