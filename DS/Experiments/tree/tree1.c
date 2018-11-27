/*this is tree1.c*/
#include<stdio.h> 
#include<stdlib.h> 
#include "tree1.h"
extern struct node *root;
struct node *current = NULL;
int ele1 = NULL;
int number_of_children(struct node *parent){
    if((parent->left != NULL) && (parent->right != NULL)){
        return 2;
    }
    else{
        if((parent->left != NULL) || (parent->right != NULL)){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int search(int element){
    current = root;
    while(root != NULL){
    if(current == NULL){
        return 0;
    }
    else{
        if(current->value == element)
            return 1;
        else{
            current = (element < current->value) ? current->left:current->right;
        }
    }
    }
    return 0;
}
int insert_element(int element){
    if(root == NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root -> value = element;
        (root -> left) = (root -> right) = NULL;
        return 1;
    }
    else{
        current = root;
        if(search(element)){
            return 0;
        }
        else{
            current = root;
            while(1){
            if(current->value < element){
                if(current->right != NULL){
                    current = current->right;
                }
                else{
                    current->right = (struct node*)malloc(sizeof(struct node));
                    current = current->right;
                    current->value = element;
                    current->right = current->left = NULL;
                    return 1;
                }
            }
            else{
                if(current->left != NULL){
                    current = current->left;
                }
                else{
                    current->left = (struct node*)malloc(sizeof(struct node));
                    current = current->left;
                    current->value = element;
                    current->right = current->left = NULL;
                    return 1;
                }
            }
        }
    }
    }
}
struct node *delete_element(struct node *base, int element){
    struct node *temp = NULL, *delete_node = NULL, *delete_node1 = NULL;
    temp = base;
    while(temp->value != element){
        delete_node = temp;
        if(temp->value > element){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    switch(number_of_children(temp)){
        case 1:{
                   if(temp == root && temp->left != NULL){
                       root = root->left;
                       free(temp);
                       break;
                   }
                   else if(temp == root && temp->right != NULL){
                       root = root->right;
                       free(temp);
                       break;
                   }
                   if(temp->left == NULL){
                       (delete_node->right) = temp->right;
                       free(temp);
                       break;
                   }
                   else{
                       (delete_node->left) = temp->left;
                       free(temp);
                       break;
                   }
               }
               break;
        case 2:{
                   delete_node = temp;
                   delete_node = delete_node->right;
                   while(delete_node->left != NULL){
                       delete_node = delete_node->left;
                   }
                   temp->value = (delete_node->value)+(temp->value);
                   delete_node->value = (temp->value) - (delete_node->value);
                   temp->value = (temp->value) - (delete_node->value);
                   ele1 = temp->value;
                   delete_element(delete_node, element);
                   ele1 = NULL;
                   break;
               }
               break;
        case 0:{
                   free(temp);
                   //temp = NULL;
                   make_null(temp, element);
                   break;
               }
    }
    return base;
}
void display_minimum(){
    current = root;
    while(current->left != NULL){
        current = current->left;
    }
    printf("Minimum element is %d\n", current->value); 
}
void display_maximum(){
    current = root;
    while(current->right != NULL){
        current = current->right;
    }
    printf("Maximum element is %d\n", current->value); 
}
void display_preorder(struct node *base){
    if(base != NULL){
        printf(" %d ",base->value); 
        display_preorder(base->left);
        display_preorder(base->right);
    }
}
void display_inorder(struct node *base){
    if(base != NULL){
        display_inorder(base->left);
        printf(" %d ",base->value); 
        display_inorder(base->right);
    }
}
void display_postorder(struct node *base){
    if(base != NULL){
        display_postorder(base->left);
        display_postorder(base->right);
        printf(" %d ",base->value); 
    }
}
void make_null(struct node *null_node, int element){
    struct node *temp = NULL;
    if(null_node == root){
        root = NULL;
    }
    else{
        temp = root;
        while(1){
            if((temp->value == ele1) && (temp->right == null_node)){
                temp->right = NULL;
                break;
            }else{
                if(temp->value == ele1)
                    temp = temp->right;
            }
        if(temp->value > element){
            if(temp->left != null_node){
                temp = temp->left;
            }
            else{
                temp->left = NULL;
                break;
            }
        }
        else{
        if(temp->value < element){
            if(temp->right != null_node){
                temp = temp->right;
            }
            else{
                temp->right = NULL;
                break;
            }
        }
        else
        {
            if((temp->value == element) && (temp->right != null_node)){
            temp = temp->right;
        }
        }
    }
}
}
}
int max;
int tree_height(struct node *base, int m){
    static int h = -1;
    if(m = -1){
        max = h = -1;
    }
    if(base != NULL){
        h++;
        max = h > max ? h: max;
        tree_height(base->left, 1);
        tree_height(base->right, 1);
        h--;
    }
    return max;
}
