/*this is tree.h*/
#ifndef _TREE_H
#define _TREE_H
struct node{/*structure for a node in tree*/ 
    int value;/*value at the node*/ 
    struct node *left;/*pointer to left subtree*/ 
    struct node *right;/*pointer to right subtree*/ 
};
int number_of_children(struct node *parent);/*to find number of children 
                                              of a node*/ 
struct node *search(struct node *base, int element);/*to search an element in 
                                                      a tree or subtree from 
                                                      base node*/

int insert_element(int element);/*to insert an element into tree*/ 
void delete_element();/*delete an element from tree */ 
void display(int choice);/*to display minimum/maximum/all elements in tree*/ 
#endif
