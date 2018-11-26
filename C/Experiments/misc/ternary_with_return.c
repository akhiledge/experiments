#include <stdio.h>
#include <stdbool.h> 

bool ret(void){
    printf (" tata \n"); 
    return true;
}
int main (void) {
    int i = 0;
    printf ("%d\n", i == 0 ? ret() : false);
    return 0;
}
