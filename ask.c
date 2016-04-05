#include <stdio.h>

void argChecker(int argc, char *argv[]);

char getAnswer(void);

int main (int argc, char *argv[]){
	/*Check args*/

	/*Print Message*/
	printf("<MESSAGE>: [y,N]: ");

	/*Check Input*/
        char c = getAnswer();

	/* Compare Input */
	int ret;
	if (c == 'y') {
		ret = 0;
	} else {
		ret = 1;
	}

	/*return option selected*/
	return ret;
}


void argChecker(int argc, char *argv[]){
	int currentArg = 1;
}

char getAnswer(void){
	char c;
	char result;

	/* get first char */
	c = getchar();
	/* store this as the result */
	/* lower case fixes many bugs */
	result = tolower(c);

	/* Clear the rest of the line */
	while (c != '\n') {
		c = getchar();
	}
	return result;
}

