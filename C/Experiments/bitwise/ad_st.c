#include<stdio.h>
int main()
{
 char *s="computer";
 fun(s);
 char *p;
 p=s;
 printf(" %x  %s ",p,p);
 return 0;
}
fun(char *s)
{
 int i=0;
 printf("%s",s);
 while(s[i]!='\0')
 {
 	if((*(s+i))=='p')
 		printf("%x,%x",s,(s+i));
 	i++;
 }

}
