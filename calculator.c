#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // string to double function

int main(){
	printf("jakubmanczak's calculator in c\n\n");

	double cNumber = 0;
	double cInputNumber = 0;
	short cOperation = 0;

	int cInputSize = 16;
	char cInput[cInputSize];
	char *cInputPtr;
	
	printf("Please input operations and numbers in a single prompt.\n");

	while(true){
		
		printf("----------------\n");
		printf("%lf\n", cNumber);
		printf("----------------\n\n");

		printf("Available inputs: +, -, *, /. 'q' to quit.\n");
		printf("Your Input: ");
		fgets(cInput, cInputSize, stdin); // get user's input

		switch(cInput[0]){
			case '+': cOperation = 1; break;
			case '-': cOperation = 2; break;
			case '*': cOperation = 3; break;
			case '/': cOperation = 4; break;
			case 'q': cOperation = -1; return 0;
			default: cOperation = 0; break;
		}

		// get rid of operator from the input
		// && also get rid of all spaces in front
		do{
			for(int i = 1; i < cInputSize; i++){
				cInput[i-1] = cInput[i];
			}
		}while(cInput[0] == ' ');
		
		// pointer is needed here apparently lol
		// converts the number in cInput string to double
		cInputNumber = strtod(cInput, &cInputPtr);

		switch(cOperation){
			case 1: cNumber = cNumber + cInputNumber; break;
			case 2: cNumber = cNumber - cInputNumber; break;
			case 3: cNumber = cNumber * cInputNumber; break;
			case 4: cNumber = cNumber / cInputNumber; break;
		}

		printf("\033c");
	}
}