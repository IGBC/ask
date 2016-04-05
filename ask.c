#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/* functions */

void argChecker(int argc, char *argv[]);

char getAnswer(void);

int compareAnswer(char c);

void showHelp(void);

/* globals */

char *message = NULL;

char optionList[100] = {'\0'};

int options = 0;

char defaultOpt = '\0';

/* function bodies */

/* main */
int main (int argc, char *argv[]){
	/*Check args*/
	argChecker(argc, argv);

	/*Print Message*/
	printf("%s: [y,N]: ",message);

	/*Check Input*/
        char c = getAnswer();

	/* Compare Input */
	int ret = compareAnswer(c);

	/*return option selected*/
	return ret;
}


void argChecker(int argc, char *argv[]){
	char c;
	while ((c = getopt (argc, argv, "m:ho:d:")) != -1){
		switch (c){
			case 'm':
				message = (char*)malloc(strlen(optarg)); 
				strcpy(message, optarg);
			case 'o':
				optionList[options++] = tolower(optarg[0]);
				break;
			case 'd':
				defaultOpt = tolower(optarg[0]);
				break;
			case 'h':
			case '?':
			default:
				showHelp();
      		}
	}
	if (options == 0){
		optionList[0] = 'y';
		optionList[1] = 'n';
		options = 2;
	}
	if (defaultOpt == '\0') defaultOpt = optionList[0];
	printf("Options: %s %i ",optionList,options);
	printf("Default: %c\n",defaultOpt);
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

int compareAnswer(char c){
	/* check if need default */
	if (c == '\n') c = defaultOpt;

	/* compare against each char */
	int i;
	for(i = 0; 1; i++){
		if (c == optionList[i])	{
			break;
		}
		if (options == i) exit(-1);
	}
	return i;
}

void showHelp(void){
	/* TODO: add help text */
	printf("HELPTEXT");
	exit(-2);
}
