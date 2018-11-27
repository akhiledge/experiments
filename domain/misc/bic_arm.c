#include <stdio.h> 

int bic (int rn, int n){
    return (rn & (~n));
}
int main (void) {
    printf (" rd=%.8x, ~n = %.8x\n", bic (0x0b1111, 0x0b0101), ~(0x0b0101)); 
    printf (" %.8x\n", bic (725265, 721153)); 
    return 0; 
}
