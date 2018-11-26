#include<stdio.h> 
#define SWAP(a,b) (a)^=(b);\
                       b^=(a)^=(b)
//#define SWAP(a,b) a^=b;\
b^=a;\
a^=b
int main(void) {
    int a[6]={1,2,3,4,5,6};
   // int l=7,k=8;
  //  int *p = &l;
  //  int *q = &k;
 //   SWAP(*p,*q);
 //  printf("%d %d" ,l,k);
 // printf("%d %d\n",*(a+1),*(a+0)); 
    printf("%d %d\n" ,a[0],a[1]); 
    SWAP(a[1],a[0]);
    printf("%d %d" ,a[0],a[1]); 
    return 0;
}
