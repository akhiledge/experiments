#include<stdio.h>
void bin(unsigned int n)
{
 unsigned int i=0;
  while(i<32)
 {
        if((n&(1 << 31-i ))==0)
                printf("0");
        else
                printf("1");
        i++;
 }
}

int left_rotate_bits_n(unsigned int num,int n)
{
 unsigned int i;
 for(i=0;i<(n%32);i++)
 {
	if((1<<31)&num)
	{
 		num=num<<1;
		num|=(1);
	}
	else
 		num=num<<1;
 }
 printf("\n after rotating num=%12u  ",num);
 bin(num);
 
 return num;
}
int main()
{
 unsigned int num1;
 int lsh;
 printf("enter num , no of left shifts");
 scanf("%u%d",&num1,&lsh);
 bin(num1);
 num1=left_rotate_bits_n(num1,lsh);

 return 0;
}

