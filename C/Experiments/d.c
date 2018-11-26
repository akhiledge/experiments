#include<stdio.h>
#include<stdlib.h> 
int main(void) {
    malloc_stats();
    int *st, *pt;
    malloc_stats();
    pt = malloc(sizeof(int)*4);
    malloc_stats();
    st = calloc(1,sizeof(int));
    malloc_stats();
    *pt = 4;
    printf("%d",*pt);
    printf(" %p %p",st,pt); 
    printf(" %x ",st-pt);  
    int *k=malloc(sizeof(int));
    malloc_stats();
    printf(" %p ",k); 

    free(st);
    free(k);
    int *l=NULL;
    l=pt - 1;
    printf("%d", *(pt)); 
    
    free(pt);
    malloc_stats();
/*    char *t=malloc(sizeof(char)*5);
    t = "ab";
    printf("%d",atoi(t));
    free(t); */
    return 0;
}
