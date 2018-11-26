#include<stdio.h>
void bin(unsigned int n)
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

int right_rot(unsigned int num,int numsh)
{
 return (num>>numsh)|(num&(~((-1)<<numsh)))<<32-numsh;
}

int main()
{
unsigned int num;
int numsh;
printf("ENTER num, no of rot ");
scanf("%u%d",&num,&numsh);
bin(num);
num=right_rot(num,numsh);
printf("\n%u  ",num);
bin (num);
}

