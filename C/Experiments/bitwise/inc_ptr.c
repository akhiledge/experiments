#include<stdio.h>
int main()
{
 int a[3]={10,20,30};
 int x=0;
 x=++a[++x] + ++x + a[--x];
 printf("%d\n" , x);

 return 0;
 
}


