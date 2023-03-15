#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp=fopen("main2.txt","w");
    FILE* mainfp = fopen("main2.c", "r");
    char program[1000];
    int i = 0;
    while (fgets(program+i, 1000-i, mainfp) != NULL) {
        i=i+strlen(program+i);
    }
    fprintf(fp,"%s",program);
    fclose(fp);
    fclose(mainfp);
    return 0;
}
