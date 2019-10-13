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
	int i = 1;
	
	while (1) {																			
		L1: if (i == 1) {
			i = (i + 3) / 2;
			goto L2;
		}
		L2: if (access(filename, F_OK) != -1) {
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
		else {
			goto L3;
		L3: fPtr = fopen(filename, "w");
			goto L4;
			
		L4:	fputs(str, fPtr);
			fclose(fPtr);
		}
	}

	return 0;
}
