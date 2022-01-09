#include <stdio.h>

#define WHAT_CASE(c) \
	if(c>= 65 && c <= 90) \
		printf("%c is uppercase", c); \
	else if(c >= 97 && c <= 122) \
		printf("%c is lowercase", c); \
	else \
		printf("%c is not letter", c);

int main() {
	char mychar = getchar();
	WHAT_CASE(mychar);
	return 0;
}
