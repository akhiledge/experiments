#include<stdio.h>
int a=10;
void main(){
int a=9;
{
extern int a;
printf("\n%d\n",a);
}{
printf("%d",*extern int  a);
}}

