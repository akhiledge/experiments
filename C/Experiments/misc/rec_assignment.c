#include <stdio.h> 
int main (void)
{
    int a = 1, b = 2, c = 3, d = 4;
    a = (b = (c = (d++)));
//    (((a = b) = c) = (d));
    printf (" %d %d %d %d\n", a, b, c, d); 
    return 0; 
}
