#include<stdio.h>
#include<stdlib.h> 
#define SIZE 100 /*Size of array*/ 
int main(void) {
    time_t ti;
    int i; /*Index value*/
    int t; /*To store random number generated */ 
    int flag=0; /*To find if a match is found or not*/ 
    int num[SIZE]; /*Integer array whose values range in between 0 & 100*/ 
    srand((unsigned) time(&ti));
    for(i=0;i<SIZE;i++){

            if(flag==0){ /*When there is no match */ 
                t=rand()%SIZE;
                num[i]=t;/*Storing values into integer array */ 
                if(num[i]==i){
                    flag=1; /*Match found */ 
//                    printf("%d match found\n",num[i]); /*Printing the value of match*/ 
                }
            }
            else{ /*When a match is found */ 
                do{
                    t=rand()%SIZE;
                }while(t==i); /*If number is same as index then taking next number*/ 
                num[i]=t;
            }
            
    }
    for(i=0;i<SIZE;i++){
        if(i%10==0)
            printf("\n"); 
        if(num[i]==i)
            printf("match found  "); 
        printf("%2d ",num[i]); /*Printing values in array*/ 
    }
    return 0;
}
