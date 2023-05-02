#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t my_time = time(NULL);
    struct tm *timeinfo = localtime(&my_time);
    printf("Time is %d:%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); 
    return 0;
}