#include<stdio.h>
int main()
{
 long long int i,num[2],pos=0,val=1,bin=1111111111111111;
 printf("num=");
 scanf("%lld",&num[0]);


 num[1]=num[0];
 



 for(i=0;i<16;i++)
 {
 	if((num[0]&(1<<i))==0)
		bin-=val;
	val*=10;
 }
 printf("%lld\n",bin);
}

