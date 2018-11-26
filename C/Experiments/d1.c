#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h> 
int main(void)
{
    int i;
    int *t=NULL, *s=NULL;
    s=(int *)malloc(13);
// t=(char *)malloc(sizeof(char));
    printf("%p %p\n",(s),t);
    printf(" \n%d\n",malloc_usable_size(s));
  //  *(s+5)=55;
    for(i=0;i<malloc_usable_size(s)/4;i++)
    printf("%x ",*(s+i)); 
   free(s);
  free(s); 
   free(t);
    return 0;
}
