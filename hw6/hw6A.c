#include <stdio.h>
#include <stdlib.h>

int main() {

    float sum = 1.0f;   //  we need to start at 1 because 1/0 is undefined behavior, which is bad
    int value = -1;     //  use -1 because we want the user to input a number between 0 and 15
    int denominator = 1;

    while(value < 0 || value > 15) {

        printf("Please enter a value between 0 and 15:\n");
        scanf("%d", &value);

    }

    for(int i = 1; i <= value; i++) {

        denominator *= i;                       //  denominator = i!
        sum += ((float)1 / (float)denominator); //  sum = 1 + 1/1! + ... + 1/i!

    }

    printf("The estimated value of e is %f\n", sum);

    return 0;

}
