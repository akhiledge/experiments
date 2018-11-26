#include<stdio.h>
#include<stdlib.h> 

void cm(int *val){
    int k;
time_t t;
srand((unsigned)(&t));
    k=(rand()%3)+1;
    if((*val)>=13&&(*val<17))
        k=(*val)-12;
    if((*val>7)&&(*val<13))
        k=(*val)-7;
    if((*val)<7)
        k=(*val)-1;

    printf("%d\n",k);
    (*val)-=k; 
}
int main(void) {
time_t ti;
srand((unsigned)(&ti));
    int i,val=21,ch;
    ch=rand()%2;
    do{
        switch(ch){
            case 0:{
                       printf("User pick in 1-5:");
                           scanf("%d",&i);
                       if(i<6 && i>0){
                           val-=i;
                           ch=1;
                           break;
                       }
                       else
                           ch=0;
                       break;
                   }
            case 1:{
                       printf("Comp:"); 
                       cm(&val);
                       ch=0;
                       break;
                   }
        }
        printf("sticks left:%d\n",val); 
    }while(val!=1);
    if(ch==0)
        printf("\nWinner is Comp\n");
    else
       printf("\nWinner is User\n"); 
   return 0; 
}
