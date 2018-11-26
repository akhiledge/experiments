#include<stdio.h>

const int *p;
int main()
{
 int k=10;
 p=&k;
*p=20;
printf("%d\n",k);

 return 0;
}
