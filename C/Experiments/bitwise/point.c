#include<stdio.h>
typedef int (*INTARR)[10];
//typedef int INTARR[10];

 INTARR a;
 INTARR b={1,2,3,5,53};
int main()
{ 
 a=&b;
 printf("%d %d",sizeof(a), sizeof(b));
 //b[5]=10;
 printf("\n%d",*(*(a+2)));
 return 0;
}
