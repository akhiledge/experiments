#include<stdio.h>

void bin(int n)
{
 int i=0;
  while(i<32)
 {
        if((n&(1 << 31-i ))==0)
                printf("0");
        else
                printf("1");
        i++;
 }
 printf("\n");
}


int bit_copy(int snum,int dnum,int n,int s,int d)
{
 int cpb=snum&(~((-1)<<n)<<(s-n+1));
 printf("\n cpb %d ",cpb );
 bin(cpb);
 printf("\n");

 dnum = dnum&(~((~((-1)<<n))<<(d-n)));
 bin(dnum);
 dnum = dnum | (cpb>>(s-d+1));

 bin(dnum);
 printf("\n dnum %d ",dnum);
 return dnum;
}



int main()
{
 int snum,dnum,n,s,d;
 printf("enter snum,dnum, n, s, d  ");
 scanf("%d%d%d%d%d",&snum,&dnum,&n,&s,&d);
 bin(snum);
 bin(dnum);
 dnum=bit_copy(snum,dnum,n,s,d);
 printf("\n snum,dnum %d , %d \n",snum,dnum);
 bin(snum);
 bin(dnum);
}
