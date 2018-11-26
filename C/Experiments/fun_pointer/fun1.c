#include<stdio.h> 
int (*f)();
int mul(int a, int b, int c){
    return (a + (b * c));
}
int add(int a, int b){
    return (a + b);
}
int main(void) {
    int a = 4;
    int b = 54;
    int c;
    f = add;
    c = f(a, b);
    printf("%d \n", c); 
    f = mul;
    c = f(a, b, 10);
    printf("%d \n", c); 
    return 3;

}
