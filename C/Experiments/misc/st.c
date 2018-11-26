#include<stdio.h>
struct cls{
int  p;
char grade;
}b[3];
void main(){

int i=0,cnt=0;
b[1].grade='F';
b[2].grade='F';
b[3].grade='T';

for(i=1;i<=3;i++)
{
cnt+=b[i].grade=='F';
}

printf("\ncnt %d\n",cnt);
}


