void header(Elf32_Ehdr head){
    int i = 0;
    printf("Elf header:\n");
    printf("%-10s","Magic:");     
    for(; i < EI_NIDENT; i++){
        printf("%2x ",head.e_ident[i]); 
    }
    puts("");
    printf("%-36s","Class:"); 
    printf((head.e_ident[EI_CLASS] == 0)?"Invalid\n":"ELF32\n");
    printf("%-36s","Data:"); 
    printf((head.e_ident[EI_DATA] == 0)?"Invalid, ":"2's complement, ");
    printf((head.e_ident[EI_DATA] == 1)?"little endian":"big endian\n");
    printf("%-36s","Version:"); 
    printf((head.e_version == 0)?"Invalid\n":"1(Current)\n");
    printf("%-36s","Machine:"); 
    switch(head.e_machine){
        case 0:{
                   printf("NONE(No machine)\n");
                  break; 
               }
        case 3:{
                   printf("Intel 80386\n");
                  break; 
               }
        case 7:{
                   printf("Intel 80860\n");
                  break; 
               }
    }
    printf("%-36s","Type:"); 
    switch(head.e_type){
        case 0:{
                   printf("NONE(No file type)\n");
                  break; 
               }
        case 1:{
                   printf("REL(Relocatable file)\n");
                  break; 
               }
        case 2:{
                   printf("EXEC(Execuatable file)\n");
                  break; 
               }
    }
    printf("%-36s0x%x\n","Entry point address:",head.e_entry); 
    printf("%-36s%d","Start of program header:",head.e_phoff);
    printf("(bytes into file)\n");  
    printf("%-36s%d","Start of section header:",head.e_shoff); 
    printf("(bytes into file)\n");  
    printf("%-36s0x%x\n","Flags:",head.e_flags); 
    printf("%-36s%d(bytes)\n","Size of this header:",head.e_ehsize); 
    printf("%-36s%d(bytes)\n","Size of program headers:",head.e_phentsize); 
    printf("%-36s%d\n","Number of program headers:",head.e_phnum); 
    printf("%-36s%d(bytes)\n","Size of section headers:",head.e_shentsize); 
    printf("%-36s%d\n","Number of section headers:",head.e_shnum); 
    printf("%-36s%d\n","Section header string table index:",head.e_shstrndx); 
}
