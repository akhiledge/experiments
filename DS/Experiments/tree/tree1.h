/*this is tree1.h*/
#ifndef _TREE1_H
#define _TREE1_H
struct node{/*structure for a node in tree*/ 
    int value;/*value at the node*/ 
    struct node *left;/*pointer to left subtree*/ 
    struct node *right;/*pointer to right subtree*/ 
};
int number_of_children(struct node *parent);/*to find number of children 
                                              of a node*/ 
int search(int element);/*to search an element in a tree or subtree 
                          from base node*/

int insert_element(int element);/*to insert an element into tree*/ 
struct node *delete_element(struct node *base, int element);/*delete an element from tree */
void make_null(struct node *null_node, int element);
void display_minimum();/*to display minimum element in tree*/ 
void display_maximum();/*to display maximum element in tree*/ 
void display_preorder(struct node *base);/*display elements of tree in preorder*/ 
void display_inorder(struct node *base);/*display elements of tree in inorder*/ 
void display_postorder(struct node *base);/*display elements of tree in postorder*/ 
int tree_height(struct node *base, int m); /*to know the height of tree*/ 
#endif
