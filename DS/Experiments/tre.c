#include<stdio.h> 
#include<stdlib.h>
#include "ato_i.h" 
#define SIZE 10

struct val{
    int data;
    struct val *left;
    struct val *right;
};
void add(struct val *rt){
    struct val *
    if(rt==NULL)

}
int main(void) {
    char *st=NULL;
    st=(char *)malloc(sizeof(char)*SIZE);
    int ch;
    struct val *root=NULL;
    do{
        printf("1.add\n2.print in ascending order\n3.print in decending order");
        printf("\n4.exit\n");
        fgets(st,SIZE,stdin); 
        ch=ato_i(st);
        switch(ch){
            case 1:{
                       add(root);
                       break;
                   }
            case 2:{
                       print_asc(root);
                       break;
                   }
            case 3:{
                       print_des(root);
                       break;
                   }
            case 4:{
                       exit(0);
                       break;
                   }
            default:{
                        printf("Please select from 1-4\n"); 
                        break;
                    }
        }
    }while(1);

    return 0;
}

