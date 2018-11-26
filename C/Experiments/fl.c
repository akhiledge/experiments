#include<stdio.h> 
#include<stdlib.h>
#define SIZE 50
int main(void) {
    char ch;
    int i=20;
    FILE *fp=NULL;
    char *str=NULL;
    str=(char *)malloc(sizeof(char)*SIZE);
    puts("ENter string");
    fgets(str,SIZE,stdin);
    printf(" ch=%p ",&ch); 
    fp=fopen("abcdd.c","a");
    /*while((*(str+(i)))!='\0'){
        fputc(*(str+i),fp);
        i++;
    }*/
//    while(fgets(str,6,fp))
    fputs(str,fp);
    //fprintf(fp,"%22s",str);
    fclose(fp);
    puts("hhhh\n");
    fp=fopen("abcdd.c","r+");
    while((ch=fgetc(fp))!=EOF){
        if(ch==70){
            fseek(fp,-1,SEEK_CUR);
            fputc(102,fp);
            }
        printf(" ft %3ld ",ftell(fp)); 
        putchar(ch);
    }
    if(fclose(fp))
        puts("\nnot closed");
    else
        puts("\nclosed"); 
    
    
    
    return 0;
}
