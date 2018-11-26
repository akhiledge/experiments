#include<stdio.h> 
#include<stdlib.h> 
#define SIZE 100
int main(void) {
    time_t ti;
    int i=0,j=0,match,flag=0,rnum,nr=0,a[SIZE];
    srand((unsigned)(&ti));
    printf("%u\n",(unsigned)(&ti)); 
    printf("%u\n",(unsigned)(ti)); 
    for(i=0;i<SIZE;i++){
        nr=0;
        do{
            rnum=rand()%100;
            for(j=0;j<i;j++){
                if(a[j]==rnum)
                    break;
            }
            if(j==i)
                nr=1;
        }while(nr!=1);
        if((flag==0)){
            if(i==rnum)
                flag=1;
            a[i]=rnum;
        }else{
            if(i==rnum)
                i--;
            else
                a[i]=rnum;
        }
    }
    for(i=0;i<SIZE;i++){
        if(i%10==0)
            printf("\n");
       if(a[i]==i)
          match=i; 
        printf("%4d",a[i]); 
    }
    if(flag==1)
        printf("match is %d",match); 
}
