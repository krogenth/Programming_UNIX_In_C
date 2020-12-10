#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bits(unsigned int input);
void displayBits(unsigned int input);

int main() {

    //  since we don't care about the input, we don't really have to test, unless you wanted us to, then we could do what I did many homeworks ago
    unsigned int input = -1;
    unsigned int reversed = -1;
    printf("Please enter an unsigned integer for bit reversal:\n");
    scanf("%u", &input);        //  use %u for unsigned decimal integers

    printf("\nUser entered:\t%10u\t", input);
    displayBits(input);
    reversed = reverse_bits(input);
    printf("Program output:\t%10u\t", reversed);
    displayBits(reversed);

    return 0;

}

unsigned int reverse_bits(unsigned int input) {

    unsigned int output = 0;

    //  we can use sizeof(), which gives the number of bytes a variable/structure uses, and multiply by 8 to get the number of bits
    for(int i = 0; i < (sizeof(input) * 8); i++) {

        //  Originally, I wanted to use inline assembly and use BSWAP: https://web.itu.edu.tr/kesgin/mul06/intel/instr/bswap.html
        //  However, that might have been even worse than this solution, so I chose not to use that

        //  For this swap algorithm, we will be starting at the least significant bit, and working our way up.
        //  To properly determine where this bit should go, we need to do some math.
        //  Since we know how many bits are used, we can go off of the max bits - 1, this is for indexing.
        //  Then, because we are moving both sides for reading and writing, we must adjust by 2i, i would work if we were adjusting only 1 side.
        if(((int)((sizeof(input) * 8) - 1) - (2 * i)) > 0)
        //  We can do some bit manipulation to grab the specific bit that we want to move, and using what was already stated, move the bit by sizeof - 1 - 2i.
        //  Which direction we shift depends entirely on the sizeof - 1 -2i outcome. If the result is positive, we shift left, otherwise, we need the abs of the result, and shift right.
            output += (input & 1 << i) << ((sizeof(input) * 8) - 1) - (2 * i);
        else
            output += (input & 1 << i) >> abs(((sizeof(input) * 8) - 1) - (2 * i));

    }

    return output;

}

void displayBits(unsigned int input) {

    for(int i = 0; i < sizeof(input) * 8; i++) {

        //  We can bitshift 1 to n-i position to mask and retrieve the desired bit, then bitshift right n-i to retrieve the bit as a 0 or 1
        printf("%u", ((input & 1 << (((sizeof(input) * 8) - 1) - i)) >> (((sizeof(input) * 8) - 1) - i)));

        //  Add spaces for byte ordering
        if((i + 1) % 8 == 0)
            printf(" ");

    }

    printf("\n");

}
