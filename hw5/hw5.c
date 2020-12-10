#include <stdio.h>
#include <stdlib.h>

void clear() {

  while ( getchar() != '\n' );

}

int main() {

    //  task 1
    printf("Number\t\t\t\tSquare\t\t\t\tCube\n");

    for(int i = 0; i <= 10; i++)
        printf("%d\t\t\t\t%d\t\t\t\t%d\n", i, (i * i), (i * i * i));

    //  task 2
    float floatsum = 0.0f;
    for(int i = 1; i <= 30; i++)
        floatsum += (float)i / (float)(30 - i + 1);

    printf("\nsum = %.4f\n\n", floatsum);

    //  task 3
    floatsum = 0.0f;
    float value = 0.0f;

    printf("Please enter a series of positive numbers(enter a negative number to end):\n");

    while (value >= 0.0f) {

        floatsum += value;

        while(!scanf("%f", &value)) {

            clear();
            printf("Please enter a number:\n");

        }

    }

    printf("sum = %f", floatsum);

    return 0;

}
