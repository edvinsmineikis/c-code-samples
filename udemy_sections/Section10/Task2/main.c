#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    
    FILE* fpin = fopen(argv[1], "r");
    FILE* fpout = fopen("output.txt", "w");

    int ch = fgetc(fpin);

    while(ch != EOF) {
        if((ch >= 'A' && ch <= 'Z')) {
            fputc(tolower(ch), fpout);
        }
        else if (ch >= 'a' && ch <= 'z') {
            fputc(toupper(ch), fpout);
        }
        else {
            fputc(ch, fpout);
        }
        ch = fgetc(fpin);
    }

    fclose(fpin);
    fclose(fpout);


    return 0;
}