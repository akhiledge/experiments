#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#define BUF_SIZE 16

struct node{
    int value;
    struct node *next;
};
struct node *start = NULL;/*start pointer for SLL*/ 

int len = 0;/*length of SLL*/ 

/*******
 * insert element into SLL at end
 **********/
int insert (int data){
    struct node *current = NULL;
    if (NULL == start){
        current = (struct node *) calloc (1, sizeof (struct node));
        if (NULL == current){
            return -1;
        }
        start = current;
    }
    else{
        current = start;
        while (NULL != (current -> next)){
            current = current -> next;
        }
        (current -> next) = (struct node *) calloc (1, sizeof (struct node));
        current = current -> next;
    }
    (current -> value) = data;
    (current -> next) = NULL;
    len++;
    return 0;
}

/*****
 * display elements in SLL
 *********/ 
int display (struct node *current){
    if (NULL == start){
        return -1; 
    }
    while (NULL != current){
        printf (" %d", (current->value)); 
        current = (current->next);
    }
    printf ("\n"); 
    return 0;
}

/*******
 * delete n th node from end in SLL
 ********/ 
int delete (int position, struct node *current){

    if ((position > len) || (position < 1))/*position is out of bound of SLL*/  
        return -1;
    if (position == len){/*position is starting of SLL*/ 
        start = (start->next);
        len--;
        return 0;
    }
    else if ((position + 2) < len){/*other position in SLL*/ 
        return delete ((position + 2), (current->next)->next);
    }
    (current->next) = (current->next)->next;
    len--;
    return 0;
}

/*******
 * delete SLL when exit option is selected 
 *******/ 
int clean (struct node *current){
    if (NULL == start){
        return 0;
    }
    else{
        current = start;
        while (NULL != current){
            start = (start->next);
            free (current);
            current = start;
        }
    }
    return 0;
}

int main (void) {
    int value = 0;
    int choice = 0;
    char *str = NULL;
    int (*fun[])() = {insert, delete, display, clean};

    str = (char *) calloc (1, sizeof (char) * BUF_SIZE);
    while (true){
        fputs ("enter an option\n1.insert\n2.delete nth element from end", stdout);
        fputs ("\n3.display\n4.exit\n", stdout);
        choice = (atoi (fgets (str, BUF_SIZE, stdin))); 
        if ((choice > 4) || (choice < 1)){
            printf ("enter a valid option\n"); 
        }
        else if(3 == choice){
            if (NULL == start)
                printf ("list is empty\n "); 
            else
                (fun[choice - 1])(start);
        }
        else if (4 == choice){
            (fun[choice - 1])(start);
            break;
        }
        else{
            if ((2 == choice) && (NULL == start)){
                printf (" linked list is empty\n"); 
                continue;
            }
            fputs ("Enter ", stdout);
            fputs ((choice == 1)?"value to insert\n":"node number to delete\n", stdout);
            memset (str, 0, BUF_SIZE);
            value = atoi (fgets (str, BUF_SIZE, stdin));
            printf ("\nvalue %stion ", (choice==1)?"inser":"dele");
            printf ("%s\n",((fun[choice - 1])(value, start)) == 0?"success":"failed");
        }
    }
    free (str);
    str = NULL;
    return 0;
}
