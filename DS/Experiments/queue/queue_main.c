#include<stdio.h>
#include<stdlib.h> 
#include "ato_i.h"
#include "queue.h"
#define SIZE 16
int main(void) {
    int choice;
    char *input = (char *)malloc(sizeof(char)*SIZE);
    while(1){
//        system("clear");
        puts("\n1.enqueue\n2.dequeue\n3.is full\n4.is empty\n5.peek\n6.Display\n");
        puts("7.size of queue\n10.Exit\n");
        __fpurge(stdin);
//        fflush(stdin);
        fgets(input,SIZE,stdin);
        choice = ato_i(input);
        printf("%d \n",choice); 
//        scanf("%d",&choice);
        switch(choice){
            case 1:{
                       enqueue();
                       break;
                   }
            case 2:{
                       dequeue();
                       break;
                   }
            case 3:{
                       if(is_full())
                           puts("queue is full\n");
                       else
                           puts("queue is not full\n");
                       break;
                   }
            case 4:{
                       if(is_empty())
                           puts("queue is empty\n");
                       else 
                           puts("queue is not empty\n");
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
                       printf("size of queue is %d",size());
                       break;
                   }
            case 10:{
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
