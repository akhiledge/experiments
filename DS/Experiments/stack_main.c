#include<stdio.h>
#include<stdlib.h> 
#include "ato_i.h"
#include "st_ack.h"
#define SIZE 16
int main(void) {
    int choice;
    char *input = (char *)malloc(sizeof(char)*SIZE);
    while(1){
        fflush(stdin);
        puts("\n1.Push\n2.Pop\n3.is full\n4.is empty\n5.peek\n6.Display\n7.Exit\n");
        fgets(input,SIZE,stdin);
        choice = ato_i(input);
        printf("%d \n",choice); 
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                       push();
                       break;
                   }
            case 2:{
                       pop();
                       break;
                   }
            case 3:{
                       if(is_full())
                           puts("stack is full\n");
                       else
                           puts("stack is not full\n");
                       break;
                   }
            case 4:{
                       if(is_empty())
                           puts("stack is empty\n");
                       else 
                           puts("stack is not empty\n");
                       break;
                   }
            case 5:{
                       pe_ek();
                       break;
                   }
            case 6:{
                       display();
                       break;
                   }
            case 7:{
                       exit(1);
                       break;
                   }
            default:{
                        puts("Please select a correct option\n");
                        break;
                    }
        }

    }
    return 0;
}
