#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h> 
#include <ctype.h>
#include <errno.h> 


#define BUF_SIZE 50 

bool is_vowel(char ptr)
{
    char arr[]={'a','e','i','o','u'};
    int i;
    for(i=0;i<5;i++){
        if ((ptr == arr[i]) | (ptr == (arr[i]^32))) 
            return true;
    }
    return false;
}
int main (int arg_cnt, char **cmdArg) 
{
    char *ptr=NULL ;
    char *tok=NULL ;
    FILE *read_fp = NULL;
    FILE *write_fp = NULL;
    int len = 0;
    int i = 0;
    char temp;
    char delim[] = {' ','\n'};

    ptr = (char *) calloc(1,sizeof(char ) * BUF_SIZE);
    /*fputs ("enter the string\n",stdout);
      fgets (ptr,BUF_SIZE,stdin);*/

    //read_fp = fopen (cmdArg[1],"r");
    //write_fp = fopen (cmdArg[2],"w");
    read_fp = fopen ("input","r+");
    write_fp = fopen ("output","w+");

    fseek (read_fp, 0, SEEK_END);
    int size = ftell (read_fp);
        rewind (read_fp);
    //fputs (cmdArg[1], stdout);
    //fputs (cmdArg[2], stdout);
    while (ftell (read_fp) != size){
    //while (feof (read_fp) ){
        //ret_val = fread (ptr, BUF_SIZE, 1, read_fp);
        fread (ptr, BUF_SIZE, 1, read_fp);
        
        perror ("readline from buffer");
        fputs (ptr, stdout);
        tok = strtok (ptr, delim);
        fputs (tok, stdout);
        while (NULL != tok){
            len = strlen (tok) - 1;
            len -= (tok[len] == '\n') ? 1 : 0 ;
            printf (" \n1%c1\n ", tok[len]); 
            if (is_vowel (tok[0]) & is_vowel (tok[len])){
                if (tok[0] == tok[len]){
                    for (i = 0; i <= len/2; i++){
                        temp = tok[i];
                        tok[i] = tok[len-i];
                        tok[len-i] = temp;
                    }
                }
                else{
                    for (i = 0; (i <= len); i++){
                        if(isalpha (tok[i]))
                            tok[i] = tok[i] ^ 32;
                    }
                }
            }
            else if (is_vowel (tok[0]) | is_vowel (tok[len])){
                fputs ("GLOBALEDGE ", write_fp);
                tok = strtok (NULL, " ");
                continue;
            }
            else {
                i = 0;
                while (i <= len){
                    if (is_vowel (tok[i]))
                        memcpy (tok + i, "*", 1);
                    i++;
                }
            }
            fputs (tok, write_fp);
            fputs (" ", write_fp);
            tok = strtok (NULL, delim);
        }
    }
    fputs (ptr, stdout); 
    free (ptr);
    ptr = NULL;
    fclose (read_fp);
    fclose (write_fp);

    return 0;
}
