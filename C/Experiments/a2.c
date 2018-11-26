#include<stdio.h> 
int main(void)
{
    int a[5]={1,2,3,4,5};
    int *f=a,*l=(4+a);
    int i;
    while(f<l){
        (*f)^=(*l)^=(*f)^=(*l);
        ++f;
        --l;
    }
    for(i=0;i<5;i++){
        printf("%d", a[i]); 
    }
printf("\n%d %d %d\n",*a,*f,*l); 
}
