#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define SIZE 16

int main(void) {
    int len,sign=1,num=0,i=0,start=1;
    char *str=(char *)malloc(sizeof(char)*SIZE);

    puts("Enter string:");
    fgets(str , SIZE , stdin);
    for(len=0;str[len]!='\0';len++){
        if(str[len]=='\n'){
            str[len]='\0';
            break;
        }
    }
        
    while((str[i]!='\0')){
        if((str[i]==' ')&&start)
            i++;
        else {
               start=0;
               if(str[i]=='+'){
                             sign=1;
                             i++;
               }
                if(str[i]=='-'){
                             sign=0;
                             i++;
                }
            
            if((str[i]>57)||(str[i]<48)){
                printf("non-integral character present in string\n"); 
                exit(0);
            }

            else{
        num*= 10;
        num +=(int)(*(str+i++)-'0');
        }
        }
    }
    if(sign==0)
        num=(-num);
    printf("%d",num);

    printf("  %d",num*2); 
    return 0;
}
