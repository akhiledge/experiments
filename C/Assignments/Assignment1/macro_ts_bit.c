#include<stdio.h>
#define bit_ts(num,pos) ((num&1<<pos)?printf("bit already set\n"):(num^=1<<pos))
void bin(int );
void main()
{
 int num,pos;
 printf("enter num, pos (0-31) ");
 scanf("%d%d",&num,&pos);
 bin(num);
 bit_ts(num,pos);
 printf("\nnum after bit set %d \n",num);
 bin(num);

}

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

