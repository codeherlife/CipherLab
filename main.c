//
//  Name this file: cipher.c
//  CipherLab
//
//  Student Name: Melanie Summers;
//  Student id: 012090935;
//  Name of the assignment: Cipher Lab;
//  Date: 11/9/18;
//  Name and version of the C Compiler: Xcode v. 9.4.1;
//  Name of Operating System: Mac OS High Sierra v. 10.13.6;
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fp, *fpIn;
int main(void);
void processFile(char array[]);
void cipher(char array[], int *shiftAmount);
void outputCode(char array[]);

int main(void) {
    int shiftAmount = 0;
    char array[1000];
    
    fp = fopen("csis.txt", "w");
    
    if(!(fpIn = fopen("congress.txt", "r"))) {
        printf(     "congress.txt could not be opened for input.");
        fprintf(fp, "congress.txt could not be opened for input.");
        exit(1);
    }
    processFile(array);
    cipher(array, &shiftAmount);
    outputCode(array);
    
    fclose(fpIn);
    fclose(fp);
    return 0;
}

void processFile(char array[]){
    char c = fgetc(fpIn);
    int i;
    
    for(i = 0; c!= EOF; c = fgetc(fpIn)){
        if(isalpha(c)){
            array[i] = toupper(c);
            i++;
        }
    }
    array[i] = '\0';
}

void cipher(char array[], int *shiftAmount){
    int i = 0;
    printf(     "Enter the number of which you would like the text to shift. \n");
    fprintf(fp, "Enter the number of which you would like the text to shift. \n");
    scanf("%d", shiftAmount);
    printf(     "The text will now be shifted this many spaces: %d\n", *shiftAmount);
    fprintf(fp, "The text will now be shifted this many spaces: %d\n", *shiftAmount);
   
    while(array[i]){
        array[i]+= *shiftAmount;
        if(!isupper(array[i])){
            array[i] = array[i] - 'Z' + 'A' - 1;
        }
        i++;
    }
}

void outputCode(char array[]){
    for(int i=0; array[i] != 0; i++){
        if(i % 50 ==0 && i!= 0){
            putchar('\n');
            putc('\n', fp);
        } else if( i % 5 ==0 && i!= 0){
            putchar(' ');
            putc(' ', fp);
        }
        putchar(array[i]);
        putc(array[i], fp);
    }
}
