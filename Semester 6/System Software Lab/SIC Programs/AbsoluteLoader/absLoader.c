#include <stdio.h>
#include <string.h>

void main() {
	FILE *inputFile, *outputFile;
	inputFile = fopen("objProg.txt", "r");
    outputFile = fopen("absOP.txt", "w");
	char type, objcode[20], progname[20], input[20];
	int sa, addr, len;

	fscanf(inputFile, "%c %s %x %x", &type, progname, &sa, &len);
	
    fscanf(inputFile, "%s", input);
	while (strcmp(input, "E") != 0) {
		if (strcmp(input, "T") == 0) {
			fscanf(inputFile, "%X %X %s", &addr, &len, input);
		}

		int i = 0;
		while (i < strlen(input) - 1) {
			fprintf(outputFile, "%06X\t%c%c\n", addr++, input[i], input[i + 1]);
			i += 2;
		}
		fscanf(inputFile, "%s", input);
	}
	fclose(inputFile);
    fclose(outputFile);
}