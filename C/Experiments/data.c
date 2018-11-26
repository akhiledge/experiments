#include<stdio.h> 
#include<stdlib.h>
#define SIZE 56
struct sugg{
    int id;/*employee id*/
    char *sug[3];/*Array of suggestions*/
    char *dif[3];/*Array of differences*/
    char *name;/*Name of employee*/
    struct sugg *next;/*Pointer to hold next employee address*/
    struct sugg *prev;/*Pointer to hold previous employee address*/
};
void rem_new_line(char *str){
    int len;
    for(len=0;*(str+len)!='\0';len++);/*Finding length of string*/
    *(str+len-1)='\0';/*Replacing new line character by null character*/
    
}
add(){
    
}
    struct sugg *start=NULL;/*Struct pointer to store start of list*/
int main(void){
    struct sugg *head=NULL;/*Struct pointer to store current node of the list*/
    int id_check,opt;
  //  puts("Enter id:");
//    fgets();    
    while(1){
        puts("1.Add\n2.Modify\n3.Display\n4.Exit");
        puts("Enter an option");
        scanf("%d",&opt);
        switch(opt){
            case 1:{
                       struct sugg *temp=();
                       add();
                       break;
                   }
            case 2:{
                       modify();
                       break;
                   }
            case 3:{
                       display();
                       break;
                   }
            case 4:{
                       exit(0);
                       break;
                   }
        }
    }
    return 0;
}
