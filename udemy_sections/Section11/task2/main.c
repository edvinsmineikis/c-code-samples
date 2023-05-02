#include <stdio.h>

int mysum(int n) {
	if(n == 1) 
		return 1;
	return n + mysum(n-1);
}

int main() {
	printf("1 to 5 is %d", mysum(5));

	return 0;
}
