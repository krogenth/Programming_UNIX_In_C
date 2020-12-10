#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortNumbers(int *x, int *y, int *z) {

    if(*x > *z) {               //  verify that extremes are sorted compared to each other, this leaves only the middle(y) value

        *x ^= *z;               //  fast value swap, better than temp value storing
        *z ^= *x;               //  see this wikipedia article on this: https://en.wikipedia.org/wiki/XOR_swap_algorithm
        *x ^= *z;

    }

    if(*x > *y) {               //  if x is greater than y, then these two values should be swapped

        *x ^= *y;
        *y ^= *x;
        *x ^= *y;

    }
    else if(*y > *z) {          //  if x is not greater than y but z is greater than y, swap y and z

        *y ^= *z;
        *z ^= *y;
        *y ^= *z;

    }

}

int main() {

    int x = 0, y = 0, z = 0;

    srand(time(NULL));

    x = rand() % 1001;          //  we want values 0 to 1000, therefore we need to modulus by 1001
    y = rand() % 1001;
    z = rand() % 1001;

    sortNumbers(&x, &y, &z);

    printf("x = %d, y = %d, z = %d", x, y, z);

    return 0;

}
