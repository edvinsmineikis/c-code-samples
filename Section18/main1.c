#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showarray(const double ar[], int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d: %lf\n", i, ar[i]);
    }
}

void fillarray(double ar[], int n) {
    for(int i = 0; i < n; i++) {
        ar[i] = (double)(rand());
    }
}

int cmpfunc (const void * a, const void * b) {
   return  *(double*)a - *(double*)b ;
}

int main() {
    srand(time(NULL));
    double rnd_ar[10];
    fillarray(rnd_ar, sizeof(rnd_ar)/sizeof(double));
    showarray(rnd_ar, sizeof(rnd_ar)/sizeof(double));
    qsort(rnd_ar, sizeof(rnd_ar)/sizeof(double), sizeof(double), cmpfunc);
    showarray(rnd_ar, sizeof(rnd_ar)/sizeof(double));
    return 0;
}