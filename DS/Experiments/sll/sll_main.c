#include<stdio.h> 
#include<stdlib.h> 
#include "/home/vinay/b86_vk.vepuri/DS/Experiments/ato_i.h"
#define SIZE 16
int main(void) 
{
    int choice; /*to select an option*/
    int position; /*to store position of insertion or deletion*/ 
    int data; /*to store element value for insertion or deletion*/  
    char *str = malloc(sizeof(char)*SIZE); /*to store the input*/
    
    while(1){
        puts("1.insert\n2.delete\n3.search\n4.display\n10.exit");
            /*operations that can be performed on the linked list*/ 
        puts("enter an option"); 
        __fpurge(stdin);/*to clear the stdin buffer*/ 
        //fgets(str, SIZE, stdin);/*to take the input*/ 
        choice = ato_i(fgets(str, SIZE, stdin));/*converting str input to integer */ 
        switch(choice){
            case 1:{
                       choice = 0;
                       puts("1.insert at begining\n2.insert at a position");
                       puts("3.insert after an element\n4.at the end");
                       do{
                           __fpurge(stdin);
                           //fgets(str, SIZE, stdin);
                           choice = ato_i(fgets(str,SIZE, stdin));
                       }while((choice > 5) && (choice < 0));
                       puts("enter the value to be added");
                       //fgets(str, SIZE, stdin);
                       data = ato_i(fgets(str, SIZE, stdin));
                       switch(choice){
                           case 1:{
                                      position = 1;
                                      insert_pos(data, position);
                                      break;
                                  }
                            case 2:{
                                       puts("enter position at which the value is to be added");
                                       fgets(str, SIZE, stdin);
                                       position = ato_i(str);
                                       insert_pos(data,position);
                                       break;
                                   }
                            case 3:{
                                       puts("eneter element after which you want to add");
                                       fgets(str,SIZE,stdin);
                                       position = ato_i(str);
                                       insert_ele(data, position);
                                       break;
                                   }
                            case 4:{
                                       position = -1;
                                       insert_pos(data, position);
                                       break;
                                   }
                       }
                       break;
                   }
            case 2:{
                       choice = 0;
                       do{
                           puts("1.delete at begining\n2.delete at end");
                           puts("3.delete at a position\n4.delete an element");
                           puts("\nenter an option to delete");
                           __fpurge(stdin);
                           choice = ato_i(fgets(str, SIZE, stdin));
                       }while((choice > 4) && (choice < 0));
                       switch (choice){
                           case 1:{
                                      position = 1;
                                      delete_element(position);
                                      break;
                                  }
                            case 2:{
                                       position = -1;
                                       delete_element(position);
                                       break;
                                   }
                            case 3:{
                                       puts("enter position of deletion");
                                       __fpurge(stdin);
                                       position = ato_i(fgets(str,SIZE,stdin));
                                       delete_element(position);
                                       break;
                                   }
                            case 4:{
                                       puts("enter element to delete");
                                       __fpurge(stdin);
                                       data = ato_i(fgets(str, SIZE, stdin));
                                       delete_element1(data);
                                       break;
                                   }
                       }
                       break;
                   }
            case 3:{
                       puts("enter element to search:");
                       data = ato_i(fgets(str, SIZE, stdin));
                       if(search(data)){
                           puts("element found");
                       }
                       else
                           puts("element not found");
                       break;
                   }
            case 4:{
                       display();
                       break;
                   }
            case 10:{
                        exit(1);
                        break;
                    }
            default:{
                        puts("enter a correct option");
                        break;
                    }
        }
    }

    return 0;
}
