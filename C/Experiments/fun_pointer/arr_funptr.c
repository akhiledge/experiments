#include<stdio.h> 
int (*f)();
int mul(int a, int b, int c){
    return (a + (b * c));
}
int add(int a, int b){
    return (a + b);
}
int main(void) {
int (*fp[2])();
    fp[0] = add;
    fp[1] = mul;
    int a = 4;
    int b = 54;
    int c;
    f = add;
    c = f(a, b);
    printf("add %d \n", c); 
    f = mul;
    c = f(a, b, 10);
    printf("mul %d \n", c); 

    c = fp[0](2, 5, 10);
    printf("add %d \n", c); 
    c = fp[1](a, b, 10);
    printf("mul %d \n", c); 


    return 3;

}
