#include <stdio.h>
#include <stdio.h>

/*
This solution was created about a year ago, when Miguel Calderon asked me
what I would do differently for this problem, since he did not like his own
solution. As at least some form of proof, here is an imgur album of screenshots
of when Miguel had taken a picture of my solution, and me asking Miguel if he still
had said screenshot on his phone: https://imgur.com/a/TiMJPaw

And yes, in the screenshot it is technically wrong, the second for loop should be std::pow(2, count + 1)

Since I had already come up with a solution, I decided to complicate things again
and see what silly things I could do. The program is set to what was asked, but
you can change the inputSize to be <= 9(the number of digits value can validly represent).

A simplified version where it only handles the 5 digit version can be found at the end.
*/

int switchValue(int value);

int main() {

    const int inputSize = 8;                                            //  for changing the max digit input size
    int combination = 1 << inputSize;                                   //  for determining the amount of combinations there are
    int value = -1;                                                     //  initialize the value so we can loop for input
    int maxValue = 1;                                                   //  for determining what the max possible number the user can input
    int input[inputSize];                                               //  array of ints for checking purposes
    int arr[combination][inputSize];                                    //  2d array for storing all possible combinations

    for(int i = 0; i < inputSize; i++)
        maxValue *= 10;                                                 //  we need to create the max value, easiest way was 1 * 10 done n times

    while(value < 0 || value >= maxValue) {

        printf("Please enter a %d digit number between ", inputSize);   //  this is slightly messy, since I figured you would want the appropriate number
        for(int i = 0; i < inputSize; i++)                              //  of digits for the 0 case as well, but storing that is weird, and I didn't want to think about it
            printf("0");
        printf(" and %d:\n", maxValue - 1);

        scanf("%d", &value);

    }

    printf("\n");                                                       //  make some space for cleaner UI

    for(int i = 0; i < inputSize; i++) {

        input[inputSize - 1 - i] = value % 10;                          //  modulus by 10 so we only get the least significant digit, and store it in the right most index
        value /= 10;                                                    //  divide by 10 so we have the next significant digit as the least significant digit to read next

    }

    //  this algorithm is weird and confusing, but I will try to explain it :(
    for(int digitCount = 0; digitCount < inputSize; digitCount++) {         //  we need to loop through each digit that input contains, we are working left to right(or right to left, either works), not top to bottom

        for(int digitPartition = 0; digitPartition < (2 << digitCount); digitPartition++) {     //  this determines how many partitions we need for this digit locations(this is a power of 2 to determine how many)
                                                                                                //  so first digit, there are 2 partitions, second has 4, third has 8, fourth has 16, fifth has 32, etc.
                                                                                                //  this helps determine when we store the "flipped" digit to ensure we get all combinations
            for(int digitPartitionIndex = 0; digitPartitionIndex < (1 << (inputSize - 1 - digitCount)); digitPartitionIndex++) {    //  now we need to go over how many spots are within whatever partition for this digit we are in
                                                                                                                                    //  this basically tells us how many times to repeat this digit or it's "flipped" digit

                if(digitPartition % 2)      //  since we are having half of the partitions be the "flipped" digit, I volunteered all of the odd numbered partitions
                    arr[digitPartitionIndex + ((1 << (inputSize - 1 - digitCount)) * digitPartition)][digitCount] = switchValue(input[digitCount]);
                else
                    arr[digitPartitionIndex + ((1 << (inputSize - 1 - digitCount)) * digitPartition)][digitCount] = input[digitCount];

            }

        }

    }

    printf("All %d combinations are:\n", combination);
    for(int i = 0; i < combination; i++) {

        printf("%d:\t", i + 1);

        for(int j = 0; j < inputSize; j++) {

            printf("%d", arr[i][j]);

        }

        printf("\n");


    }

    return 0;

}

int switchValue(int value) {

    if(value % 2) {      //  value is odd

        if(value == 9)
            return 0;
        else
            return value + 1;

    }
    else {

        if(value == 0)
            return 9;
        else
            return value - 1;

    }

}

/*
#include <stdio.h>
#include <stdio.h>

int switchValue(int value);

int main() {

    int value = -1;
    int input[5];
    int arr[32][5];

    while(value < 0 || value > 99999) {

        printf("Please enter a 5 digit number between 00000 and 99999:\n");
        scanf("%d", &value);

    }

    printf("\n");

    for(int i = 0; i < 5; i++) {

        input[4 - i] = value % 10;
        value /= 10;

    }

    for(int digitCount = 0; digitCount < 5; digitCount++) {

        for(int digitPartition = 0; digitPartition < (2 << digitCount); digitPartition++) {

            for(int digitPartitionIndex = 0; digitPartitionIndex < (1 << (4 - digitCount)); digitPartitionIndex++) {

                if(digitPartition % 2)
                    arr[digitPartitionIndex + ((1 << (4 - digitCount)) * digitPartition)][digitCount] = switchValue(input[digitCount]);
                else
                    arr[digitPartitionIndex + ((1 << (4 - digitCount)) * digitPartition)][digitCount] = input[digitCount];

            }

        }

    }

    for(int i = 0; i < 32; i++)
        printf("%d%d%d%d%d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4]);

    return 0;

}

int switchValue(int value) {

    if(value % 2) {      //  value is odd

        if(value == 9)
            return 0;
        else
            return value + 1;

    }
    else {

        if(value == 0)
            return 9;
        else
            return value - 1;

    }

}
*/
