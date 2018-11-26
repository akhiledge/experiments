#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void tower_of_honoi(int disk1,char src1,char aux1,char dest1);
int main(void)
{
    int disk;
    char *str=(char *)malloc(sizeof(char)*MAX);
    printf("enter the number of disks\n");
    fgets(str,MAX,stdin);
    disk=atoi(str);
    tower_of_honoi(disk,'A','B','C');
    return 0;
}
void tower_of_honoi(int disk1,char src1,char dest1,char aux1)
{
    if(disk1==1)
    {
        printf("disk 1 moves from %c to %c\n",src1,dest1);
        return;
    }
    else
    {
        tower_of_honoi(disk1-1,src1,aux1,dest1);
        printf("disk %d moves from %c to %c\n",disk1,src1,dest1);
        tower_of_honoi(disk1-1,aux1,dest1,src1);
    }
}
