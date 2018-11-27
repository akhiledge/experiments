VPATH = source object header

CSRC = allocate_memory.c balance.c inorder.c insert.c left_rotate.c main.c postorder.c preorder.c right_rotate.c sibling.c user_input.c value_in_node.c

OBJ = allocate_memory.o balance.o inorder.o insert.o left_rotate.o main.o postorder.o preorder.o right_rotate.o sibling.o user_input.o value_in_node.o


rb_tree : $(OBJ)
	gcc -o $@ $^ 
	mv *.o object

$(OBJ) : $(CSRC)
	gcc -include header/rb_tree.h -g -c $^

