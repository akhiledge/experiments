#include<stdio.h> 
#include<stdlib.h>
#define SIZE 75
void str_cpy (char *dbuf,char *sbuf)
{
	int i=0;
	while(sbuf[i]!='\0')
	{
		*(dbuf+i)=*(sbuf+i);
			i++;
	}
	*(dbuf+i)='\0';
}
int main()
{
 char *sbuf=NULL,*dbuf=NULL;
 sbuf=(char *)malloc(sizeof(char)*SIZE);
 dbuf=(char *)malloc(sizeof(char)*SIZE);
 printf("enter the string:");
 scanf("%s",sbuf);
 str_cpy (dbuf,sbuf);
 printf("sbuf:%s dbuf:%s",sbuf,dbuf);

 return 0;
}

