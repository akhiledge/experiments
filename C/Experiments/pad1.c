#include<stdio.h>

struct p{
//    char a,b;
  //  float d;
    double c;
    short int e;
    //char f;
};
struct st{
    char a;
    double b;
    int g;
};
int main(void)
{
    printf("size %d",sizeof(struct st)); 
    return 0;
}
