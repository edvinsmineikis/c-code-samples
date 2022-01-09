#include <stdio.h>

int main() {
    unsigned int input;
    printf("Enter value: ");
    scanf("%u", &input);
    printf("\nBit 2 is: %d\n", ((input & 0x2) > 0));
    input = input & ~(0x8);
    printf("4th bit is now changed to 1, value is now: %d\n", input);
}