
struct node {
    int value;
    struct node* next;
};
struct node * start = NULL;/*start pointer to SLL*/ 
int len;/*length of SLL*/

/*******
 * delete n th node from end in SLL
 ********/ 
int delete (int position, struct node *current){
    
    if (position > len)/*position is out of bound of SLL*/  
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

