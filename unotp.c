#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *inputFile, *keyFile;
    int inputCharacter, keyCharacter;

    if(argc != 3) {
        printf("Usage: otp Inputfile Keyfile\n");
        printf("Error: Too few arguments\n");
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    keyFile = fopen(argv[2], "r");

    if(inputFile == NULL || keyFile == NULL) {
        printf("Error while openening files\n");
        return 1;
    }

    while((inputCharacter = getc(inputFile)) != EOF) {
        keyCharacter = getc(keyFile);
        putchar(inputCharacter ^ keyCharacter);
    }

    fclose(inputFile);
    fclose(keyFile);
    return 0;
}
