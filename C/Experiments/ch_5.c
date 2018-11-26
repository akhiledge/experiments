#include<stdio.h>
#include <string.h> 
int main(void){
    char a[10] = {1,2,3,4,5,6,7,8,9,10};
    short int i,g;
    memcpy(&g,a+5,2);
    i = (a[5]<<8) + (a[6]);
    printf(" %.4x %.4x\n",i,g); 
    return 0;
}
