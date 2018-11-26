#include<stdio.h>
void bin(int ); 
int even_bit_toggle(int );
void main()
{
 int num;
 printf("enter num ");
 scanf("%d",&num);
 bin(num);
 printf("\n");
 num=even_bit_toggle(num);
 printf("\nnumber after toggle %d\n ",num);
 bin(num);
}


int even_bit_toggle(int n)
{
 int i=0;
 while(i<32)
 {
 	n^=(1<<i);
	i+=2;
 }
 return n;
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

