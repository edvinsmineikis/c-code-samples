#include <stdio.h>

#define SUM(a, b) (a) + (b)
#define SQUARE(x) (x) * (x)
#define CUBE(x) (x) * (x) * (x)

int main() {
	printf("Time is %s\n", __TIME__);
	printf("5 + 3 = %d\n", SUM(5, 3));
	printf("2 squared is %d and cubed is %d\n", SQUARE(2), CUBE(2));
	return 0;
}
