/*this is tree.c*/
struct node *traverse_ptr = NULL;
int number_of_children(struct node *parent){
    if((parent -> left != NULL) && (parent -> right != NULL)){
        return 2;
    }
    else{
        if((parent -> left == NULL) || (parent -> right == NULL)){
            return 1;
        }
        else{
            return 0;
        }
    }
}
struct node *search(struct node *base, int element){
    traverse_ptr = base;
    if(traverse_ptr == NULL){
        return traverse_ptr;
    }
    else{
        if(traverse_ptr -> value == element){
            return traverse_ptr;
        }
        else{
            switch(number_of_children(traverse_ptr)){
                case 0:{
                           return NULL;
                           break;
                       }
                case 1:
                case 2:{
                           if(traverse_ptr->value > element)
                               traverse_ptr = search(traverse_ptr->left, element);
                           else
                               traverse_ptr = search(traverse_ptr->right, element);
                           return traverse_ptr;
                           break;
                       }
            }
        }
    }
}
int insert_element(int element){
}
void delete_element(){
}
