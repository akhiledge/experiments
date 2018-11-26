#include<stdio.h>
#pragma pack(16)
struct v{
    int a;
    double g;
    char c;
};
int main(void) 
{
    struct v fs;
    fs.a=4;
    fs.a++;
    printf("%d",fs.a); 
    return 0;
}
