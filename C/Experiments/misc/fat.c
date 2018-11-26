#include <stdio.h> 
#define a 2
int main (void) {
    int ak=4;
    printf (" %d",ak);

#ifdef a 
    printf (" %d ", a);
#endif 


    return 0; 
}
