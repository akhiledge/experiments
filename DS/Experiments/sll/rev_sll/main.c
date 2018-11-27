#include "rev_sll_header.h"

int main (void) {
    start = NULL;
    length = 0;

    int (*fun_ptr[])(int) = {insert, rev, display};
    int choice = 0;
    int data = 0;
    char *str = NULL;

    str = (char *) calloc (NMEMBER, sizeof (char) * BUF_SIZE);

    while(1){
        fputs ("Enter your choice\n",stdout);
        fputs ("1.insert\n2.rev\n3.display\n4.exit\n", stdout);
        choice = atoi (fgets (str, BUF_SIZE, stdin));
        if ((choice < 3) && (choice > 0)){
            fputs ("Enter value ", stdout);
            memset (str, 0, BUF_SIZE);
            data = atoi (fgets (str, BUF_SIZE, stdin));
        }
        else if (choice == 4)
            break;
        else if (choice != 3){
            fputs ("enter a valid option\n", stdout);
            continue;
        }
        fun_ptr[choice - 1](data);
    }

    return 0;
}
