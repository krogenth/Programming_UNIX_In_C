#include <stdio.h>

void clear () {

  while ( getchar() != '\n' );

}

int main() {

    int amount = 0;
    int error = 0;
    printf("Please enter a dollar amount:\n");
    error = scanf("%d", &amount);

    while(!error) {

        clear();
        printf("Please enter a dollar amount:\n");
        error = scanf("%d", &amount);

    }

    printf("$20 bills = %d\n", amount / 20);
    amount %= 20;

    printf("$10 bills = %d\n", amount / 10);
    amount %= 10;

    printf("$5 bills = %d\n", amount / 5);
    amount %= 5;

    printf("$1 bills = %d\n", amount);

    return 0;

}
