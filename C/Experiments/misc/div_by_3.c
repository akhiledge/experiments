
#define SHIFT_3(X) CHECK((X<<1)>>3)
#define SHIFT_1(X) CHECK(X>>1)
int CHECK(int X){
return ((X==1||X==2) ? 0 : ((X==0) ? 1 : ((X&1)?SHIFT_3(X):SHIFT_1(X))));
}

#include <stdio.h> 

int main( int argc, char ** argv ){
    int number = atoi(argv[1]);
    if( CHECK(number)){
            printf ("Divisible by 3\n ");
            }
    else
            printf ("not Divisible \n ");

 return 0; 


}

