/*****
 * find greatest number in array
 * ****/ 
#include<stdlib.h> 
#include<stdio.h>
#define swap(num1,num2) (num1^=num2^=num1^=num2)
void gr(int *a,int *b)
{
    int i=31;
    while(i!=-1)
    {
        if((*a&(1<<i))^(*b&(1<<i)))
        {
            if((*a&(1<<i)))
            {
                swap(*a,*b);
                i=0;
            }

        }
        printf("%d,",*a); 
        i--;
    }
}
 int greatest(int *a)
{
    int j=0;
    printf("abc"); 
    printf("%d..",*(a+j)); 
    while(j!=10)
    {
        gr(&a[j+1],&a[j]);
        printf("%d.",a[j]); 
        j--;
    }
    return a[9];
}
int main(void)
{
    int grt,i=0,a[10];
    printf("enter numbers into array:\n"); 
    for(i=0;i!=10;i++)
    {
        scanf("%d",&a[i]);
    }
    grt=(greatest(a)); 
    for(i=0;i!=10;i++)
    printf("%d ",a[i]); 

    return 0;
}
