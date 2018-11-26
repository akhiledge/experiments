#include<stdio.h> 
#include<stdlib.h>

struct mn{
    char  a[30];
};
void prin(struct mn *s){
    printf("%s\n", s->a); 
}

struct mn *start=NULL;
int main(void) {
    
    struct mn *p;
    p=(struct mn *)malloc(sizeof(struct mn));
    start=p;
    puts("Enter");
    scanf("%s",start->a);
    prin(start);
    return 0;
}
