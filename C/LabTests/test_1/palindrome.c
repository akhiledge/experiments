#include<stdio.h> 
#include<stdlib.h> 
#define BUF_SIZE 50
int main(void) {
    char *str = NULL ;
    int len, i, flag;
//    str = (char *) malloc (sizeof(char) * BUF_SIZE);
    fgets(str, BUF_SIZE, stdin);
    for(len = 0; str[len] != '\0'; len++ ){
        if('\n' == str[len]){
            str[len] = '\0';
//            break;
        }
    }
    for(i = 0, flag = 1; i < (len/2); i++ ){
        if(str[i] != str[len - i - 1]){
            flag = 0;
            break;
        }
    }
    printf("The given string is%sa palindrome\n%d",flag?" ":" not ",len); 
    return 0;
}
