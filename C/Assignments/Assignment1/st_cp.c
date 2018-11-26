#include<stdio.h>
void st_cp(char *s, char *d)
{
 int i=0;
 while(s[i]!='\0')
 {
    d[i]=s[i];
	i++;

 }
 
}
int main()
{
 char s[56];
 scanf("%s",s);
 char d[56];
 printf("%x %x\n",s,d);
 st_cp(s,d);
 printf(" %s %s",s,d);
}

