#include <stdio.h>
#include <stdarg.h>

int addsum(int count, ...) {
	
	int sum = 0;
	va_list list1;
	va_start(list1, count);
	
	for(int i = 0; i < count; i++) {
		sum += va_arg(list1, int);
	}

	return sum;
}

int main() {
	printf("1 + 2 + 3 = %d", addsum(3, 1, 2, 3));

}
