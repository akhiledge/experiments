#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#define BUF_SIZE 50 

int is_vowel(char ptr)
{
    char arr[]={'a','e','i','o','u'};
    int i;
    for(i=0;i<5;i++){
        if ((ptr == arr[i]) | (ptr == (arr[i]^32))) 
            return 1;
    }
    return 0;
}

int main(void)
{
    char *ptr=NULL ;
    ptr = (char *) calloc(1,sizeof(char ) * BUF_SIZE);
    fputs ("enter the string\n",stdout);
    fgets (ptr,BUF_SIZE,stdin);
    int len = strlen (ptr) - 2;
    int i;
    char temp;

    if (is_vowel (ptr[0]) && is_vowel (ptr[len])){
        for (i = 0; i <= len/2; i++){
            temp = ptr[i];
            ptr[i] = ptr[len-i];
            ptr[len-i] = temp;
        }
    }
    else if (is_vowel (ptr[0]) | is_vowel (ptr[len])){
        for (i = 0; i <= len; i++){
            ptr[i] = ptr[i] ^ 32;
        }
    }
    else {
        memcpy (ptr, "globaledge", 10);
    }
    fputs (ptr, stdout); 
    free (ptr);
    ptr = NULL;

    return 0;
}
