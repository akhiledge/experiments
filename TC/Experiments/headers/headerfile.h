#ifndef _HEADERFILE_H
#define _HEADERFILE_H
#include<stdio.h> 
#include<stdlib.h> 
#include<elf.h>   
#define BUF_SIZE 20
void header(Elf32_Ehdr head);/*@param head
                                @breif this function printd ELF header contents*/ 
void section(Elf32_Shdr sec);/*@param sec 
                                @breif this function prints section header contents*/ 

#endif
