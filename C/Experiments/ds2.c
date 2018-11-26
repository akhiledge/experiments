#include<stdio.h> 
typedef struct name{
    long a;
    int b;
    long c;
}r;
r re={3,4,5};
int main(void) {
    r *na=&re;
    printf("%d",*(int *)((char *)na+(unsigned int)&(((struct name*)0)->b))); 
    printf(" %d",(&((struct name*)0)->b)); 
    printf("%d",*(char *)na); 
    return 0;
}
