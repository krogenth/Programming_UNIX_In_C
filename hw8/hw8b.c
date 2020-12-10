#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    /*
    //  This is the maximum 2d array of x^2 I could create on my machine
    int width = 717;
    int height = width;

    int arr[width][height];

    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            arr[i][j] = rand() % 1001;

    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            printf("%d\n", arr[i][j]);
    */

    //  This stackoverflow thread goes over the maximum size of arrays in c99 very well: https://stackoverflow.com/questions/9386979/what-is-the-maximum-size-of-an-array-in-c
    //  Essentially, SIZE_MAX determines the theoretical max size, but currently the hardware is unable to support up to that size.
    //  Additionally requiring continuous memory to fulfill the request as well, which will limit the max possible size further.

    //  we will use 2 different arrays, one to store the values, and one to count the number of instances of those values
    //  since we are only allowing values of 0 to 6 inclusively, we can reference the count array index by the value
    int* arr = (int*)malloc(5000*5000*sizeof(int));
    int arrCount[7] = {0,0,0,0,0,0,0};

    if(arr == NULL) {

        printf("Not enough sequential memory!\n");
        exit(1);

    }

    for(int i = 0; i < 5000*5000; i++) {

        //  generate the random number, go to the count array's index, and increment the value
        *(arr + i) = rand() % 7;
        arrCount[*(arr + i)]++;

    }

    for(int i = 0; i < 7; i++)
        printf("Number of %d:\t%d\n", i, arrCount[i]);

    free(arr);

    return 0;

}
