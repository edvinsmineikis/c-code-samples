#include <stdio.h>

void changeptr(int **ptr) {
	int a = 10;
	*ptr = &a;
}

int main() {
	int a = 5;
	int *ptr = &a;
	printf("Val of ptr is %p", ptr);
	changeptr(&ptr);
	printf("Val of ptr is %p", ptr);

	return 0;
}
