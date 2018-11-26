#include<stdbool.h> 
#include<stdio.h> 
enum choice{j,k,l}ch;
int main(void) {
    int a;
    bool s = false;
    scanf("%d", &a);
    scanf("%d", &ch);
    //ch = a;
    if((a*=5) == 5)
        printf("%d",a);
    else
       printf("nothing");  
    if(ch)
        printf("\nwefyg");
    else
       printf("\nqqqqqq");  
    return 0;
}
