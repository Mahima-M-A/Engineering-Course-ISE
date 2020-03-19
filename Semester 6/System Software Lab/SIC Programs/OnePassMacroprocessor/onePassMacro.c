#include <stdio.h>
#include <string.h>

void main() {
	FILE *f1, *f2, *f3;
	char label[20], opcode[20], operand[20], macroname[20];
	strcpy(macroname, "");
	f1 = fopen("macin.txt", "r");
	f2 = fopen("macout.txt", "w");
	fscanf(f1, "%s %s %s", label, opcode, operand);

	while (strcmp(opcode, "END") != 0) {
		if ((strcmp(opcode, "MACRO") != 0) && (strcmp(opcode, macroname) != 0))
			fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);

		else if (strcmp(opcode, macroname) == 0) {
			f3 = fopen("deftab.txt", "r");
			fscanf(f3, "%s %s %s", label, opcode, operand);
			fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);
			fscanf(f3, "%s %s %s", label, opcode, operand);
			while (!feof(f3)) {
				fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);
				fscanf(f3, "%s %s %s", label, opcode, operand);
			}
			fclose(f3);
		}
		else if (strcmp(opcode, "MACRO") == 0) {
			f3 = fopen("deftab.txt", "w");
			strcpy(macroname, label);
            fscanf(f1, "%s %s %s", label, opcode, operand);
			while (strcmp(opcode, "MEND") != 0) {
				fprintf(f3, "%s\t%s\t%s\n", label, opcode, operand);
				fscanf(f1, "%s %s %s", label, opcode, operand);
			}
			fclose(f3);
		}
		fscanf(f1, "%s %s %s", label, opcode, operand);
	}
	fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);

	fclose(f1);
	fclose(f2);
}