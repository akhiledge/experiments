#include<stdio.h> 
enum mon {jan, feb};
int main(void) {
    enum mon a = 10;
    enum mon b = jan;
    printf("a %d\n",a); 
    printf("sizeof a  %d\n",sizeof(a)); 
    printf("b %d\n",b); 
    printf("sizeof b  %d\n",sizeof(b)); 
    return 11;
}
