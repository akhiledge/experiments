#include <stdio.h> 
#include <stdlib.h> 
struct node{
    int value;
    struct node *next;
};
int main (void)
{
    struct node *current = calloc (1, sizeof (struct node));
    (current->value) = 12;
    if (NULL == (current->next)){
        printf ("%dnull\n ", (current->value)); 
    }
    else
        printf ("%d no null\n ", (current->value)); 
    return 0; 
}
