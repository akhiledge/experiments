#include<stdio.h>
#include<string.h>
#if 0
int main()
{
int * a = (1,2);
printf("%d %d",a[0],a[1]);
return 0;
}
#endif
#if 0
int main()
{
int a[][3] = {1,2,3,4,5,6};
printf("%d \n",a[1,1][1,2]);
return 0;
}
#endif
#if 0
int main()
{
char * a = "hello";
char * b = " hello";
 printf("%*.*s \n",3,2,a);
return 0;
}
#endif
#if 0
int main()
{
int i = 0;
*(&i) = 25;
printf("%d",i);
return 0;
}
#endif
int main()
{
int far  a =10;
int * arr[] = {&a};
printf("%d",*arr[0]);

return 0;
}
