#ifndef _REV_SLL_HEADER_H
#define _REV_SLL_HEADER_H
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define NMEMBER 1
#define BUF_SIZE 16

typedef struct Node{
    int value;
    struct Node *next;
}node;

node *start;
int length;

int insert (int data);
int rev (int member_in_group);
int display (int data);
#endif
