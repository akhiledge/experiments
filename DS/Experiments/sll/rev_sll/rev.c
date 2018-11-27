#include "rev_sll_header.h"
int rev (int members_in_group){
    int group_no = length/members_in_group;
    node *current = NULL;
    if (NULL == start)
        return -1;
    else
        current = start;
    int no_swaps = 0;
    node *members[members_in_group];
    node * temp = NULL;
    int idx  = 0 ;
    node *block_prev = NULL;

    while (group_no --)
    {
       no_swaps = members_in_group;
        while (no_swaps > 0){
            no_swaps--;
            members[members_in_group - no_swaps - 1] = current;
            if (NULL != current)
                current = current->next;
            else
                break;
        }

        for(idx = 1 ;idx < members_in_group ; idx++)
        {
            temp = members[idx] -> next;
            members[idx] -> next = members[idx - 1];
        }
        if(start == members[0])
            start = members[members_in_group - 1];
        else{
   //     if (group_no != ((length/members_in_group) - 1)){
            block_prev -> next = members[members_in_group - 1];
        }
        members[0] -> next = temp;
        block_prev = members[0];
    }
    return 0;
}
