#include<stdio.h> 
#include<stdlib.h> 
#include "sll.h"
struct node{
    int value;
    struct node *next;
};
struct node *start = NULL;
struct node *current = NULL;
void insert_pos(int data, int position){
    if(position < 1){
        puts("invalid position");
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    current = start;
    temp->value = data;
    if(position == -1){
        if(current == NULL){
            position = 1;
        }
        else {
            while(current->next){
                current = current->next;
            }
        }
    }
    if(position == 1){
        temp->value = data;
        temp->next = start;
        start = temp;
        return;
    }
    else
    {
    while(--position > 1){
        if((current->next == NULL) || (position == 2)){
            puts("couldn't find that position");
            return;
        }
        current = current->next;
    }
    }
    temp->next = current->next;
    current->next = temp;
}
void insert_ele(int data, int element){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    current = search(element);
    if(current){
        temp->next = current->next;
        current->next = temp; 
    }
    else{
        free(temp);
        temp == NULL;
    }
}
struct node *search(int element){
    current = start;
    if(current){
        while((current != NULL) && (current->value != element)){
            current = current->next;
        }
        /*if(current == NULL){
            puts("element not found");
        }*/
        return current;
    }
    else{
        return current;
    }
}
void display(){
    current = start;
    if(NULL == current){
        puts("linked list is empty");
        return;
    }
    puts("values in linked list are:");
    while(current)
    {
        printf("%d ",current->value);
        current = current->next; 
    }
    puts("");
}
void delete_element(int position){
    if(position < 1){
        puts("invalid position");
        return;
    }
    current = start;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(start){
        if((-1 == position) && (NULL == current->next)){
            position = 1;
        }
        if(position == 1){
            start = start->next;
            free(current);
            current = NULL;
            return;
        }
        else{
            
            getchar();
            temp=current->next;
            while((--position > 1) && (temp->next != NULL) ){
            getchar();
            printf("%d ",position); 
                current = current->next;
            temp=current->next;
            }
            if(position > 1){
                puts("position not found");
                return;
            }
            temp = current->next;
            current->next = temp->next;
            free(temp);
            temp = NULL;
        }       
    }
    else{
        puts("no elements in list to delete");
    }
}
void delete_element1(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = search(data);
    if(temp == start){
        delete_element(1);
        return;
    }
    current = start;
    if(current){
        while(current->next != temp){
            current = current->next;
        }
        current->next = temp->next;
        free(temp);
        temp = NULL;
    }
    else{
        puts("element not found");
    }
}
