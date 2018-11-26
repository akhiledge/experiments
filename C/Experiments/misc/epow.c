#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
int main (void) {
    unsigned long long int num = pow (10, 9) + 8;
    unsigned long long int idx = 2, flag;
    for (; num < pow (10, 10); num++){
        flag = 0;
        for (idx = 2; idx <= round (sqrt (num)); idx++){
            if (0 == (num % idx)){
                flag++;
                break;
            }
        }
        if (flag == 0){
            printf ("%llu \n", num);
            return 0;  
        }


    }
    return 0;
}
