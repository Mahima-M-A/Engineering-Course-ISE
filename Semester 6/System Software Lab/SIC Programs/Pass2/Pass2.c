#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	FILE *input, *optab, *symtab, *output;
	char label[20], opcode[20], operand[20];
	int address, sa;
	input = fopen("Input.txt", "r");
	output = fopen("Output.txt", "w");
	fscanf(input, "%x %s %s %s", &address, label, opcode, operand);
	if (strcmp(opcode, "START") == 0) {
		fprintf(output, "%X\t%s\t%s\t%s\t-\n", address, label, opcode, operand);
		sa = address;
	}

	fscanf(input, "%x %s %s %s", &address, label, opcode, operand);
	while (strcmp(opcode, "END") != 0) {
		fprintf(output, "%X\t%s\t%s\t%s\t", address, label, opcode, operand);
		optab = fopen("Optab.txt", "r");
		char tempcode[20], tempval[20];
		fscanf(optab, "%s %s", tempcode, tempval);
		while (!feof(optab)) {
			if (strcmp(opcode, tempcode) == 0) {
				fprintf(output, "%s", tempval);
				if(strcmp(opcode, "RSUB") == 0) {
					fprintf(output, "0000\n");
				}
				break;
			}
			else
				fscanf(optab, "%s %s", tempcode, tempval);
		}
		fclose(optab);

		char actoperand[20];
		strcpy(actoperand, "");
		if (operand[strlen(operand) - 1] == 'X') {
			int i;
			for (i = 0; i < strlen(operand) - 2; i++)
				actoperand[i] = operand[i];
			actoperand[i] = '\0';
		}
		else
			strcpy(actoperand, operand);

		symtab = fopen("Symtab.txt", "r");
		char symcode[20], symval[20];
		fscanf(symtab, "%s %s", symcode, symval);
		while (!feof(symtab)) {
			if (strcmp(actoperand, symcode) == 0) {
				int lval = strtol(symval, NULL, 16);
				if (operand[strlen(operand) - 1] == 'X')
					lval = lval + 0x8000;
				fprintf(output, "%X\n", lval);
				break;
			}
			else
				fscanf(symtab, "%s %s", symcode, symval);
		}
		fclose(symtab);

		if (strcmp(opcode, "WORD") == 0) {
			int val = strtol(operand, NULL, 16);
			char num[10];
			sprintf(num, "%X", val);
			int l = strlen(num);
			while (l < 6) {
				fprintf(output, "0");
				l++;
			}
			fprintf(output, "%s\n", num);
		}

		if (strcmp(opcode, "BYTE") == 0) {
			if (operand[0] == 'X') {
				for (int i = 2; i < strlen(operand) - 1; i++)
					fprintf(output, "%c", operand[i]);
				fprintf(output, "\n");
			}
			else if (operand[0] == 'C') {
				for (int i = 2; i < strlen(operand) - 1; i++) {
					fprintf(output, "%X", operand[i]);
				}
				fprintf(output, "\n");
			}
		}

		if (strcmp(opcode, "RESB") == 0 || strcmp(opcode, "RESW") == 0)
			fprintf(output, "-\n");

		fscanf(input, "%x %s %s %s", &address, label, opcode, operand);
	}
	fprintf(output, "%X\t%s\t%s\t%s\n", address, label, opcode, operand);

	fclose(input);
	fclose(output);
}