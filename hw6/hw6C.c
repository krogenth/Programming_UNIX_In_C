#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//I realize this is over complicated, but I wanted to experiment and see what I could do

//  used to iterate over the entire array to remove spaces
int removeWhitespace(char* buffer) {

    int count = 0;
    const char* temp = buffer;
    do {

        while(*temp == ' ')                         //  if the value the temp pointer position is a space, advance the pointer to the next position
            temp++;

    } while((*buffer++ = *temp++) && ++count);      //  set the array's next value to what the temp pointer's value is, also keep count, to know the size of the string

    return count;

}

//  used to remove x amount of char's from buffer array
void removeChar(char* buffer, int* bufferSize, int size) {

    const char* temp = buffer + (sizeof(char) * size);  //  we need a temp array at the position that excludes the number of characters we just read
    while((*buffer++ = *temp++));                       //  we need to adjust the array, so start reading chars from temp's position into buffer's position

    *bufferSize -= size;                                //  since we technically removed chars, we need to adjust the bufferSize
    *buffer = '\0';                                     //  set the end of the buffer to null('\0') to ensure nothing weird happens

}

//  for converting from a char array to an integer
void readInt(int* arg, char* buffer, int* bufferSize) {

    //  an integer can't be more than 11 digits, so we should have an array of 12, just in case it needs to be null-terminated for atoi
    char toConvert[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    int toConvertSize = 0;

    //  in case there are negative numbers, we need to check if the next char is a '-'
    if(*buffer == '-') {

        toConvert[0] = '-';
        toConvertSize++;

    }

    //  while the next unread char is between '0' and '9', add it to the toConvert char array
    while(*(buffer + (sizeof(char) * toConvertSize)) >= '0' && (*(buffer + (sizeof(char) * toConvertSize)) <= '9')) {


        toConvert[toConvertSize] = *(buffer + (sizeof(char) * toConvertSize));
        toConvertSize++;

    }

    //  convert the new array to a usable int, then remove the read chars from the original buffer
    *arg = atoi(toConvert);
    removeChar(buffer, bufferSize, toConvertSize);

}

int main() {

    //  we need an array that can accommodate basically anything
    //  NOTE: LINE_MAX is *nix based, and will not work on windows
    char buffer[LINE_MAX];
    int bufferSize = 0;

    //  we need to have 2 arguments, since all possible operations require 2 arguements
    int arg1 = 0, arg2 = 0;
    char opCode = '\0';

    printf("Please enter an expression:\n");
    scanf("%[^\n", buffer);                                 //  we can grab the entire buffer up to the new line character
    bufferSize = removeWhitespace(buffer);                  //  we can remove all of the spaces within the buffer as well
    buffer[bufferSize] = '\0';                              //  the string needs to be null-terminated

    //  initialize arg1(our answer) with the first value in the expression
    readInt(&arg1, buffer, &bufferSize);

    //  since we will be removing elements from the buffer until there is nothing left to read, we can go until bufferSize is 0(false)
    while(bufferSize) {

        opCode = buffer[0];
        removeChar(buffer, &bufferSize, 1);

        readInt(&arg2, buffer, &bufferSize);

        switch(opCode) {

        case '+':
            arg1 += arg2;
            break;

        case '-':
            arg1 -= arg2;
            break;

        case '*':
            arg1 *= arg2;
            break;

        case '/':
            arg1 /= arg2;
            break;

        default:
            break;

        }

    }

    printf("answer = %d\n", arg1);

    return 0;

}
