#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char ch = argv[1][0];
    char* buffer;
    size_t bufsize = 255;
    size_t characters;

    FILE* fp = fopen(argv[2], "r");
    if(!fp) {
        puts("file open failure");
        exit(0);
    }
    
    buffer = (char*)malloc(bufsize);
    characters = getline(&buffer, &bufsize, fp);

    while(characters != -1) {
        for(int i = 0; i < characters; i++) {
            if(buffer[i] == ch) {
                puts(buffer);
                break;
            }
        }
        
        characters = getline(&buffer, &bufsize, fp);
    }

    fclose(fp);
    free(buffer);
    return 0;
}