#include <stdio.h>

int array1[] = {10,20,30,40,50,60,70,80,90,100};
int array2[] = {38,27,87,63,59,223,132,1,19,7};


int add(int a, int b) {return a+b;}
int sub(int a, int b) {return a-b;}
int mult(int a, int b) {return a*b;}
int div(int a, int b) {return a/b;}

int main() {

	int (*func_ptr) (int, int);
	char selection;

	while(1) {
		printf("Which operation do you want to perform?\n");
		printf("1. Add\n");
		printf("2. Subtract\n");
		printf("3. Multiply\n");
		printf("4. Divide\n");
		printf("5. None\n");
		printf("Enter choice: ");
	
		selection = getchar();
		
		switch(selection) {
			case '1':
				func_ptr = add;
				break;
			case '2':
				func_ptr = sub;
				break;
			case '3':
				func_ptr = mult;
				break;
			case '4':
				func_ptr = div;
				break;
			default:
				printf("Alright bro\n");
				break;
		}
		printf("Results are:\n");
		for(int i = 0; i < sizeof(array1) / sizeof(int); i++) {
			printf("%d\t", (*func_ptr)(array1[i], array2[i]));
		}
		printf("\n");
		getchar();
	}

	return 0;
}
