#include <stdio.h>

union student {
	char letterGrade;
	int roundedGrade;
	float exactGrade;
};

int main() {
	
	union student var1;
	union student var2;

	var1.letterGrade = 'j';
	var1.roundedGrade = 5;
	printf("Var1 letter grade is %c\n", var1.letterGrade);
	printf("Var1 rounded grade is %d\n", var1.roundedGrade);

	var2.letterGrade = 'A';
	printf("Var2 lettergrade is %c", var2.letterGrade);

	return 0;
}
