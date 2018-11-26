#include<stdio.h>
union a{
    int j;
    double k;
}v;


int main(void){
  
    v.j=8;
    v.k=2.8;
    printf("%d %lf",v.j,v.k); 
}

