#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float nums[50];
    for(int i = 0; i < sizeof(nums)/sizeof(int); i++) {
        nums[i] = (float)(rand()) / RAND_MAX - 0.5F;
        printf("%d: %f\n", i, nums[i]);
    }

    return 0;
}