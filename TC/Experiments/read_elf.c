#include "headers/headerfile.h"
int main(int argc, char **argv){
    char *str = NULL;
    str = (char *)malloc(sizeof(char)*BUF_SIZE);
    FILE *exfl = NULL;
    exfl = fopen(argv[1], "rb");
    Elf32_Ehdr head;
    fread(&head, sizeof(Elf32_Ehdr), 1, exfl);
    header(head);
    Elf32_Shdr sec;
    fread(&sec, sizeof(Elf32_Ehdr), 1, exfl);
    section(sec);
    fclose(exfl);
    return 0;
}

