#include<stdio.h> 
int main(void) {
    int a=2096,b=2097;
    FILE *fp = NULL;
    fp = fopen("tf1.txt", "w");
    fprintf(fp,"%d%d",a,b);
    fclose(fp);
    fp = fopen("tf2.txt","w");
    fwrite(&a,1,4,fp);
    fwrite(&b,1,4,fp);
    fclose(fp);
    return 0;
}
