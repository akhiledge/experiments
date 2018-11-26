#include<stdio.h> 
int main(void)
{
    int j = 23;
    int i =  8;
    int k;
    k = add(i, j);
    printf("k = %d\n", k);
   i++; 
    return 0;
}
int add (int a, int b){
    return (a + b);
}
