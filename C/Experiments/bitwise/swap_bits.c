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
 int num,s,d;
 printf("num,s,d");
 scanf("%d%d%d",&num,&s,&d);
 
 (s>d)?SWAP(s,d):1;
 printf("number before bit swaping %d: ",num);
 bin(num);
 if(((num&(0x01<<s-1)))==((num&(0x01<<d-1))>>abs(d-s)))
 	1;
 else
 {
	num^=(1<<s-1);
	num^=(1<<d-1);
 }
 printf("\n number after bit swaping %d : ",num);
 bin(num);

 return 1;
}


