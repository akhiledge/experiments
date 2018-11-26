#include<stdio.h>
#include<stdlib.h> 
int main(void) {
    int size = 0, part_size = 0;
    FILE *fs = NULL, *d = NULL;
    char *str = NULL;
    fs = fopen("vp.txt","r");/*open file abc.txt using fs*/ 
    if(fs==NULL){
        printf("file not found\n");
        exit(1);
    }
    fseek(fs,0,SEEK_END);
    size = ftell(fs);
    printf("size=%d\n",size); 
    fseek(fs,0,SEEK_SET);
    part_size = size/4;
    str = (char *)malloc(sizeof(char)*part_size);
//    fclose(fs);
    d = fopen("dest.txt","w");/*open file dest.txt using d*/ 
    if(d==NULL){
        puts("file not found");
        exit(1);
    }
    printf("fd = fs %d d %d\n",fs,d); 
 //   printf("%p\n%p\n",fs,d); 

    fgets(str,part_size+2,fs);
    puts(str); 
    fprintf(d,"%s",str);
    puts(str); 
  fgets(str,part_size+2,fs);
    puts(str); 
    fprintf(d,"%s",str);
    puts(str); 
    fgets(str,part_size+2,fs);
    puts(str); 
    fprintf(d,"%s",str);
    puts(str); 
    fgets(str,part_size,fs);
    puts(str); 
    fprintf(d,"%s",str);
    puts(str); 
    part_size%=4;

    fgets(str,part_size,fs);
    fprintf(d,"%s",str);
    puts(str);
    print_ptr(fs);
    print_ptr(d);
    fclose(fs);/*closing file dest.txt using d*/ 
    print_ptr(fs);
    print_ptr(d);
    fclose(d);/*closing file abc.txt using fs*/ 
    print_ptr(fs);
    print_ptr(d);
    return 0;
}

void print_ptr( FILE * stream)
{
    printf("Read_end :%p\n",stream->_IO_read_end);
    printf("Read_cur :%p\n",stream->_IO_read_ptr);
    printf("Read_base :%p\n",stream->_IO_read_base);
    printf("write_end :%p\n",stream->_IO_write_end);
    printf("write_cur :%p\n",stream->_IO_write_ptr);
    printf("write_base :%p\n\n",stream->_IO_write_base);
}
