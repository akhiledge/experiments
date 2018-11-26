/******
 *changes case of all alphabets in a given file
 ******/ 
#include<stdio.h> 
#include<stdlib.h> 
int main (int arg_cnt, char **cmdArg) {
    char ch = '\0';
    FILE *fp=NULL;
    fp = fopen (*(cmdArg + 1),"r+");
//    ch=fgetc(fp);
//        printf(" %ld %c",ftell(fp),ch);
    while((ch=fgetc(fp)) !=EOF){
//        printf(" %ld %c",ftell(fp),ch);
//            fseek(fp,-1,SEEK_CUR);
        if(ch>64 && ch<91){
//            printf("%ld,",ftell(fp)); 
            fseek(fp,-1,SEEK_CUR);
            fputc(ch+32,fp);
        }
        else if(ch>96 && ch<123){
            fseek(fp,-1,SEEK_CUR);
            fputc(ch-32,fp);
        }
    }
    fclose(fp);
    return 0;
}
