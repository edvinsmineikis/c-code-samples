#include <stdio.h>

int evaluate(int a) {

    int prime = 1;
    if(a <= 0 || a == 1) {
        prime = 0;
    }
    for(int i = 2; i <= a / 2; i++) {
        if(a % i == 0) {
            prime = 0;
        }
    }
    if(prime) {
        printf("%d is prime\n", a);
        return 0;
    }

    if(a % 2 == 0) {
        printf("%d is even\n", a);
    }
    else {
        printf("%d is odd\n", a);
    }
    
    return 0;
}

int main() {
    FILE* fp = fopen("num.txt", "r");

    int str1;
    int foo;

    foo = fscanf(fp, "%d", &str1);

    while(foo != EOF) {
        evaluate(str1);
        foo = fscanf(fp, "%d", &str1);
    }

    fclose(fp);

    return 0;
}