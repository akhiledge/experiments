#include<stdio.h> 
    struct A{
       unsigned  int a:4;
unsigned        int b:4;
    };
    
int main(void) {
    struct A v={-1,-1};
    printf("%u %u",v.a,v.b); 
}
