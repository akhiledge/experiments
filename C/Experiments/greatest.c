/*******
 * find greatest number in an array
 * *******/ 
#include<stdio.h> 
 
#define swap(g,h) (g^=h^=g^=h)
int greatest(int *a){
    int i=31,j=0,g,gt;
    while(j!=9)
    {
    i=31;
    if(((a[j]&(1<<i))^(a[j+1]&(1<<i))))
    {
        if(~(a[j]&(1<<i)))
            swap(a[j+1],a[j]);
        else
            g=a[j+1];
    }
    else
    {
    while(i!=-1){
        i--;
        if(((a[j]&(1<<i))^(a[j+1]&(1<<i))))
        {
            if(~(a[j]&(1<<i)))
                swap(a[j+1],a[j]);
            else
                g=a[j+1];
            break;
        }
    }
    }
    printf(",%d %d,\n",a[j],a[j+1]); 
 j++;   
}
return a[9];

}

int main(void){
    int a[10],i;
    puts("Enter numbers into array:");
    for(i=0;i!=10;i++){
        scanf("%d",&a[i]);
    }
    printf("Greatest in array is %d\n",greatest(a)); 
    for(i=0;i!=10;i++)
        printf(".%d.",a[i]);     
    return 0;
}

