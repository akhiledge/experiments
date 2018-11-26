/**
 *Variables with same name globally and locally.
 *Print(use) global value locally.
 **/ 
#include<stdio.h>
int a=23;
int main(){
    int a=9;
    printf("a=%d\n",a);
    {
        extern a;
        printf("a===%d\n",a);
    }
    printf("a====%d\n",a);
}


