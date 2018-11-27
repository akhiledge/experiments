/*this is main.c */
#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h> 
#include "/home/vinay/b86_vk.vepuri/DS/Experiments/ato_i.h"
#include "tree1.h"
#define BUF_SIZE 16
struct node *root = NULL;
int main(void) {
    char *str = NULL;
    str = (char *)malloc(sizeof(char) * BUF_SIZE);
    int data;
    int choice;
    int height;
    puts("Binary search tree");
    while(true){
        puts("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
        puts("Enter your choice");
        __fpurge(stdin);
        choice = ato_i(fgets(str, BUF_SIZE, stdin));
        switch(choice){
            case 1:{
                       puts("Enter element to insert");
                       __fpurge(stdin);
                       data = ato_i(fgets(str, BUF_SIZE, stdin));
                       if(search(data)){
                           puts("Element already in tree");
                       }
                       else{
                           if(insert_element(data)){
                               puts("Element inserted ");
                           }
                           else{
                               puts("Element not inserted");
                           }
                       }
                       break;
                   }
            case 2:{
                       if(root == NULL){
                           puts("Tree is empty");
                           break;
                       }
                       puts("Enter element to delete");
                       __fpurge(stdin);
                       data = ato_i(fgets(str, BUF_SIZE, stdin));
                       if(search(data)){
                           delete_element(root, data);
                           puts("Element deleted");
                       }
                       else{
                           puts("Element not found");
                       }
                       break;
                   }
            case 3:{
                       if(root == NULL){
                           puts("Tree is empty");
                           break;
                       }
                       puts("Enter element to search");
                       __fpurge(stdin);
                       data = ato_i(fgets(str, BUF_SIZE, stdin));
                       if(search(data)){
                           puts("Element found");
                       }
                       else{
                           puts("Element not found");
                       }
                       break;
                   }
            case 4:{
                       if(root == NULL){
                           puts("Tree is empty"); 
                           break;
                       }
                       puts("Display\n  1.Minimum element");
                       puts("  2.Maximum element\n  3.All elements");
                       puts("  4.Height");
                       __fpurge(stdin);
                       choice = ato_i(fgets(str, BUF_SIZE, stdin));
                       switch(choice){
                           case 1:{
                                      display_minimum();
                                      break;
                                  }
                           case 2:{
                                      display_maximum();
                                      break;
                                  }
                           case 3:{
                                      puts("    1.preorder\n    2.inorder");
                                      puts("    3.postorder");
                                      __fpurge(stdin);
                                      choice = ato_i(fgets(str, BUF_SIZE, stdin));
                                      switch(choice){
                                          case 1:{
                                                     display_preorder(root);
                                                     puts("");
                                                     break;
                                                 }
                                          case 2:{
                                                     display_inorder(root);
                                                     puts("");
                                                     break;
                                                 }
                                          case 3:{
                                                     display_postorder(root);
                                                     puts("");
                                                     break;
                                                 }
                                          default:{
                                                      puts("Enter correct option");
                                                      break;
                                                  }
                                      }
                                      break;
                                  }
                            case 4:{
                                       height = tree_height(root, -1) + 1;
                                       if(height > 0){
                                           printf("height = %d\n", height);
                                       }
                                       else{
                                           puts("Tree is empty");
                                       }
                                       break;
                                   }
                            default:{
                                        puts("Enter correct option");
                                        break;
                                    }
                       }
                       break;
                   }
            case 5:{
                       exit(1);
                       break;
                   }
            default:{
                        puts("Please enter a correct option");
                        break;
                    }
        }

    }

    return 0;

}
