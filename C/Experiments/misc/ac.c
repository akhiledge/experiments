 #include<stdio.h>
#include<string.h>
void main(){

char a[]="copied";
memset(a+2,'z',2);
printf("%s",a);
}


