#include<stdio.h> 
#include<stdlib.h> 
#define BUF_SIZE 50
char *my_rindex(const char *str, int c){
    int len;
    for(len = 0; str[len + 1] != '\0'; len++){
        ;
    }
    for( ; len >= 0; len--){
        if(c == *(str+len)){
            return (str+len);
        }
    }
    return NULL;
}
int main(void) {
    int i = 0;
    char *str = NULL, *occurence, c;
    str = (char *) malloc (sizeof(char) * BUF_SIZE);
    fgets(str, BUF_SIZE, stdin);
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
    scanf("%c",&c);
    occurence = my_rindex(str, c);
    if(occurence){
        puts(occurence) ; 
    }
    else
        puts("not found");
    free(str);
    return 0;
}
