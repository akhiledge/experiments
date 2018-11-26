#include<stdio.h> 
#define SWAP(a,b) a= a^b;\
b=a^b;\
a=a^b
int main(void) {
//    int a[6]={1,2,3,4,5,6};
    int l=7,k=8;
    SWAP(l,k);
   printf("%d %d" ,l,k);
 // printf("%d %d\n",*(a+1),*(a+0)); 
   // SWAP(a[1],a[0]);
    //printf("%d %d" ,a[1],a[0]); 
    return 0;
}
