#include<stdio.h>
#include<math.h>
#define SWAP(a,b) (a^=b^=a^=b)
int main()
{
 int num,s,d,i=0;
 printf("num,s,d");
 scanf("%d%d%d",&num,&s,&d);
 
 (s>d)?SWAP(s,d):1;
 printf("%d %d %d\n",num,s,d);
 if(((num&(0x01<<s-1)))==((num&(0x01<<d-1))>>abs(d-s)))
	printf("%d\t",num);
 else
 {
	
 }
 while(i<32)
 { 
	if((num&(1 << 31-i ))==0)
		printf("0");
	else
		printf("1");
 	i++;
 }
 return 1;
}


