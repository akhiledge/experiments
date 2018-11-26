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
}

int count_bit_set(int num)
{
 int i=0,cnt=0;
 while(i<32)
 {
 	if(num&(1<<31-i))
		cnt++;
 i++;
 }
 return cnt;
}

int main()
{
int num;

printf("ENTER num ");
scanf("%d",&num);
bin(num);
//count_bit_set(num);
printf("\nnumber of bit set = %d  ",count_bit_set(num));

}

    
