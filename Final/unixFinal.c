#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
I chose to use the unistd.h library, which gives me the getopt function
while I cannot use exactly 'e' and 'd' for options, I can use '-e' and '-d'
It's not exactly what was asked for, but I wanted to try using something created for this purpose
of parsing command line arguements

for some reason, trying to use 'e' and 'd' causes it to malfunction, which is pretty weird
*/

void printHelp(char* file);
void encrypt(char* filename);
void decrypt(char* filename);
void getUserInput(char keys[]);
void swap(char* a, char* b);

int main(int argc, char *argv[]) {

    if(argc != 3) {

        printf("Incorrect arguements passed!");
        return EXIT_FAILURE;

    }

    int opt = 0;

    //  loop through all command line arguements, check what we have
    while((opt = getopt(argc, argv, "edh")) != -1) {

        switch(opt) {

        case 'd':
            decrypt(argv[2]);
            break;
        case 'e':
            encrypt(argv[2]);
            break;
        case 'h':
        default:
            //  a helpful function to print how to use the program
            printHelp(argv[0]);
            break;

        }

    }

    return EXIT_SUCCESS;

}

void printHelp(char* file) {

    //  it prints out some helpful information :)
    printf("/%s.exe [option] [filename]\n", file);
    printf("options:\t-d\tto decrypt file\n");
    printf("        \t-e\tto encrypt a file\n");
    printf("        \t-h\tfor help");

}

void encrypt(char* filename) {

    //  open the files to reading/writing, we can open them in binary mode because we're doing binary manipulation
    FILE* input = fopen(filename, "rb");
    FILE* output;
    char keys[2] = {'\0', '\0'};            //  for storing the keys to use
    int returnedObjs = 0;

    if(!input) {

        printf("%s failed to open!\n", filename);
        exit(EXIT_FAILURE);

    }

    //  read the file size in bytes
    //  rewind the file to read the contents
    int size = -1;
    fseek(input, 0, SEEK_END);
    size = ftell(input);
    rewind(input);

    //  create an array to store entire contents of file
    char* fileData = (char*)(malloc(size));
    returnedObjs = fread(fileData, sizeof(char), size, input);
    if (returnedObjs != size)
        printf("Failed to read all data from %s!\n", filename);
    fclose(input);                          //  close input file, we have read all we need

    getUserInput(keys);                     //  prompt user for keys

    output = fopen("output.txt", "wb");     //  open output file, since we will be writing data soon
    if(!output) {                           //  verify that output is opened

        printf("output.txt failed to open!\n");
        exit(EXIT_FAILURE);

    }

    for(int i = 0; i < (size - 1); i += 2) {

        for(int j = 0; j < 2; j++) {

            swap(&fileData[i], &fileData[i+1]);
            fileData[i+1] ^= keys[j];

        }

    }

    if((size % 2) == 1)                     //  we check to see if there was an odd number of bytes, if there was, there is one more byte to xor
        fileData[size - 1] ^= keys[1] ^ keys[0];

    //  now write out the data to the output file
    returnedObjs = fwrite(fileData, sizeof(char), size, output);
    if (returnedObjs != size)
        printf("Failed to write all data to output.txt!\n");

    free(fileData);
    fclose(output);

}

void decrypt(char* filename) {

    //  the encryption and decryption are the same algorithm, so call the encryption algorithm to decrypt the file
    encrypt(filename);

}

void getUserInput(char keys[]) {

    //  have a buffer to store data
    char str[50];
    memset(&str[0], 0, sizeof(str));

    //  verify that keys are filled
    while(!keys[0] || !keys[1]) {

        printf("Please enter 2 keys space separated:\n");
        gets(str);
        //  if the input does not match what we are expecting, then we must ask again without filling either key
        if(str[1] == ' ' && str[3] == '\0') {

            keys[0] = str[0];
            keys[1] = str[2];

        }
        else
            //  since input was not correct, we should refill the buffer with NULL
            memset(&str[0], 0, sizeof(str));

    }

}

void swap(char* a, char* b) {

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;

}
