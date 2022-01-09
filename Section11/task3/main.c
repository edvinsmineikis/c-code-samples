#include <stdio.h>

int GCD(int n1, int n2) {
	if(n1<1 || n2 < 1) {
		return n1;
	}
	return GCD(n1, n2);
}

char reverse_string(char* mystring, int n) {
	if(n == 0) {
		return mystring[0];
	}
	printf("%c", mystring[n]);
	return reverse_string(mystring, n-1);
}

int main() {
	char mystring[30];
	// printf("GCD of 10 and 50 is %d\n", GCD(10, 50));
	printf("Enter string: ");
	scanf("%s", mystring);
	reverse_string(mystring, sizeof(mystring));
	return 0;
}
