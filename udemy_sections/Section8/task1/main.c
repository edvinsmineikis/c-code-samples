#include <stdio.h>

int main() {
    long long bin = 0b01001001;
    printf("01001001 is %lld\n", bin);
    
    printf("73 is: ");
    for(int i = 7; i >= 0; i--) {
        printf("%d", (int)((bin>>i)&1));
    }
    printf("\n");
    

}