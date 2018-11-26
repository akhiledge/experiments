#include<stdio.h> 
void strn_cpy(char *dbuf, char *sbuf, int n)
{
 int i=0;
 printf("\n%d",n);
 while(i<n)
 {
  dbuf[i]=sbuf[i];
  i++;
 }
 dbuf[i]='\0';
}
int main()
{
 int n;
 char sbuf[50],dbuf[50];
 printf("enter the string :");
 scanf("%s",sbuf);
 printf("enter n val:");
 scanf("%d",&n);
 strn_cpy(dbuf,sbuf,n);
 printf("sbuf:%s dbuf:%s",sbuf,dbuf);

 return 0;
}
