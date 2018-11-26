#include<stdio.h> 

int main(void) {
    char ch;/*to store character at the current position*/ 
    int l=0,c=0,w=0,cl=0;/*count for lines-l,words-w,characters-c&cl*/ 
    FILE *fp=NULL;      
    fp=fopen("abcdd.c","r+");
    while((ch=fgetc(fp))!=EOF){
        if(ch==10){
            l++;
            w++;
        }
        if(ch==' ')
            w++;
        cl++;
    }
    c=ftell(fp);
    fclose(fp);
    printf("l=%dw=%dc=%dcl=%d",l,w,c,cl);
    return 0; 

}
