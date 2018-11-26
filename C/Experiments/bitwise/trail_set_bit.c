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

int cnt_trailing_set_bits(int num)
{
 int i=0,cnt=0;
 while(i<32)
 {
 	if((num&(1<<i)))
		cnt++;
	else
		break;
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

printf("\nnumber of trailing bits set = %d  ",cnt_trailing_set_bits(num));

}




