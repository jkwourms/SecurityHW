#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DATA_SIZE 1000

int main() {
	FILE * fPtr;
	char contents[DATA_SIZE];
	char data[DATA_SIZE];
	const char *filename = "PE-1.txt";
	const char *str = "I want to learn PE file format!";

	//check if PE-1.txt exists in root directory
	if (access(filename, F_OK) != -1) {
		// is yes, check contents of file & print to stdout if valid, if not append string to file
		fPtr = fopen(filename, "r");
		if(fgets(contents, DATA_SIZE, fPtr) != NULL) {
			if((strstr(contents, str)) != NULL) {
				printf("%s\n", contents);
				return(0);
			}
			else {
				fputs(str, fPtr);
			}
		}
		fclose(fPtr);
	}
	// if not, create file
	else {
		fPtr = fopen(filename, "w");
		fputs(str, fPtr);
		fclose(fPtr);
	}

	return 0;
}
