#include<stdio.h> 
struct name{
    int p;
    struct {
        int s;
    };
};

int main(void) {
    struct name vin ={.p=6,{.s=111}};
    printf("%d %d\n", vin.s, vin.p); 
    return 0;
}
