#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *randomSource, *inputFile, *keyFile;
    int inputCharacter, randomCharacter;

    if(argc != 3) {
        printf("Usage: otp Inputfile Keyfile\n");
        printf("Error: Too few arguments\n");
        return 1;
    }

    randomSource = fopen("/dev/urandom", "r"); //This should be /dev/random, need ideas for the blocking
    inputFile = fopen(argv[1], "r");
    keyFile = fopen(argv[2], "w");

    if(randomSource == NULL || inputFile == NULL || keyFile == NULL) {
        printf("Error while openening files\n");
        return 1;
    }

    while((inputCharacter = getc(inputFile)) != EOF) {
        randomCharacter = getc(randomSource);
        putchar(inputCharacter ^ randomCharacter);
        fputc(randomCharacter, keyFile);
    }

    fclose(randomSource);
    fclose(inputFile);
    fclose(keyFile);
    return 0;
}
