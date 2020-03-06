#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addTextRecord(FILE *objProg, int address) {
    fprintf(objProg, "\nT %06X",address);
}

void addObjCodes(FILE *objProg, char objCodes[][10], int startAdd, int numOfCodes) {
    for(int i=startAdd; i<numOfCodes; i++) {
        fprintf(objProg, " %s", objCodes[i]);
    }
}

void main() {
    FILE *input,*objProg;
    input = fopen("input.txt","r");
    objProg = fopen("objProg.txt","w");

    char objCodes[20][10], label[20], opcode[20], operand[20], objCode[10],slabel[20];
    int sa, address, loc[20], i=0, j=1, totlen;

    fscanf(input, "%X %s %s %s %s", &address, label, opcode, operand, objCode);
    if (strcmp(opcode, "START") == 0) {
        sa = address;
        loc[i++] = sa;
        strcpy(slabel, label);
    }

    fscanf(input, "%X %s %s %s %s", &address, label, opcode, operand, objCode);
    while(strcmp(opcode, "END") != 0) {
        loc[i++] = address;
        if(strcmp(objCode, "-") != 0)
            strcpy(objCodes[j++], objCode);
        else
            strcpy(objCodes[j++], "ffffff");
        fscanf(input, "%X %s %s %s %s", &address, label, opcode, operand, objCode);
    }

    totlen = address - sa; //total length

    fprintf(objProg, "H %s %06X %06X", slabel, sa, totlen);

    int recLen=0, stro, stri ,flag = 1;
    stro = loc[1];
    stri = 1;
    addTextRecord(objProg, stro);
    for(i=1; i<j; i++) {
        if(strcmp(objCodes[i],"ffffff") != 0 && (recLen/2) <= 30) {
            recLen += strlen(objCodes[i]);
        }
        else {
            fprintf(objProg, " %02X", (recLen/2));
            addObjCodes(objProg, objCodes, stri, i);
            if(i+1<j) {
                stro = loc[i+1]; //start address of text record
                stri = i+1; //start index of text record
                if(strcmp(objCodes[i+1],"ffffff") != 0) {
                    addTextRecord(objProg, stro);
                    flag = 1;
                }
                else {flag = 0; }
                recLen = 0;
            }
        }
    }
    fprintf(objProg, "\nE %06X", sa);

    fclose(input);
    fclose(objProg);
}