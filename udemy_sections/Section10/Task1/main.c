#include <stdio.h>

int readfile() {

    FILE *fd = fopen("inputc.txt","r");
    if(!fd)
        printf("error");
    
    int chars = 1;
    int words = 1;
    int ch = fgetc(fd);

    while(ch != EOF) {
        if(ch != '\n') {
            chars++;
        }
        else {
            words++;
        }
        ch = fgetc(fd);
    }
    printf("There are %d chars and %d words", chars, words);

    return 0;
}

int readstdin() {
    int chars = 1;
    int words = 1;
    int ch = getchar();

    while(ch != EOF) {
        if(ch != '\n' && ch != ' ') {
            chars++;
        }
        else {
            words++;
        }
        ch = getchar();
    }
    printf("There are %d chars and %d words", chars, words);

    return 0;
}

int main(int argc, char* argv) {

    if(argc>1) {
        readfile();
    }
    else {
        readstdin();
    }

    return 0;
}
