#include <stdio.h>
#include <stdlib.h>

void clear () {

  while ( getchar() != '\n' );

}

int main() {

    int pocket = 0;
    int error = 0;
    printf("Enter a pocket number to check(0 to 36):\n");
    error = scanf("%d", &pocket);

    while(!error) {

        clear();
        printf("Enter a pocket number to check(0 to 36):\n");
        error = scanf("%d", &pocket);

    }

    if(pocket == 0)
        goto green;
    else if (pocket < 11) {

        if(pocket % 2)  //  odd
            goto red;
        else
            goto black;

    }
    else if (pocket < 19) {

        if(pocket % 2)  //  odd
            goto black;
        else
            goto green;

    }
    else if (pocket < 29) {

        if(pocket % 2)  //  odd
            goto red;
        else
            goto black;

    }
    else if (pocket < 37) {

        if(pocket % 2)  //  odd
            goto green;
        else
            goto red;

    }
    else
        printf("Invalid Number\n");

    green:
    printf("Green\n");
    return 0;

    red:
    printf("Red\n");
    return 0;

    black:
    printf("Black\n");
    return 0;

}
