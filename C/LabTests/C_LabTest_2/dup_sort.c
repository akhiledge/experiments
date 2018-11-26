#include<stdio.h> 
#define swap(a,b) ((a)^=(b)^=(a)^=(b))

int main(void) {
    int i=0,j=0,t,dup=0;
    int a[3]={222,3};
    int b[8]={2,-5,4,0,6};

    for(i=0,j=7;i<3;i++){ /*Coping elements of a to b */ 
        b[j]=a[i];
        j--;
    }

    for(i=0;i<8;i++){ /*Checking for duplicates*/ 
        for(j=i+1;j<8;j++){
            if(b[j]==b[i]){ /*If found replace duplicate value with (2^32)-1 */ 
                b[j]=2147483647;  
                dup++ ; /*Incrementing number of duplicates found */ 
            }
        }
    }

    for(i=0;i<8;i++){ /*Sorting*/ 
        for(j=i+1;j<8;j++){
            if(b[j]<b[i]){
                t=b[j];
                b[j]=b[i];
                b[i]=t;
            }
        }
    }

    for(;dup>0;dup--)
        b[8-dup]=0;
    printf("\n"); 
    for(i=0;i<8;i++){
        printf("%d ",b[i]); 
    }
    
    return 0;
}
