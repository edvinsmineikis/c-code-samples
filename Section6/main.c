#include <stdio.h>
#include <malloc.h>

struct myArray {
    int mylength;
    int array[];
};

int main() {
    int length;
    printf("Enter size of array: ");
    scanf("%d", &length);
    
    struct myArray *mystruct;
    mystruct = malloc(sizeof(struct myArray) + length * sizeof(int));
    
    mystruct->mylength = length;
    for(int i = 0; i < length; i++) {
        mystruct->array[i] = i*10;
    }

    for(int i = 0; i < length; i++) {
        printf("%d\n", mystruct->array[i]);
    }

    return 0;
}
