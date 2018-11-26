#include<stdio.h>
#include<math.h>
#define SWAP(a,b) (a^=b^=a^=b)
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
}

int main()
{
 
 int flag=0,snum,s,d,dnum;
 printf("snum ,dnum ,s(0-31),d(0-31)");
 scanf("%d%d%d%d",&snum,&dnum,&s,&d);
 
 printf("\nnumber before bit swaping %6d: ",snum);
 bin(snum);

 printf("\nnumber before bit swaping %6d: ",dnum);
 bin(dnum);
 
 if(d>s)
	 flag=(((snum&(1<<s)))==((dnum&(1<<d))>>abs(d-s)))?1:0;
 else
	 flag=(((dnum&(1<<d)))==((snum&(1<<s))>>abs(d-s)))?1:0;
 if(flag) 
	1;
 else
 {
	snum^=(1<<s);
	dnum^=(1<<d);
 }
 printf("\nnumber after bit swaping %6d: ",snum);
 bin(snum);

 printf("\nnumber after bit swaping %6d: ",dnum);
 bin(dnum);


 return 1;
}


