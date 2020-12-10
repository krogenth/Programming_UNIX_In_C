#include <stdio.h>
#include <stdlib.h>

struct fraction {

    int numerator;
    int denominator;

};

int gcd(int a, int b);
struct fraction fracSum(struct fraction frac1, struct fraction frac2);
void fracPrint(struct fraction frac);

int main() {

    struct fraction frac1;
    struct fraction frac2;

    //  get information needed to fill fractions
    printf("Please enter an integer for the first numerator:\n");
    scanf("%d", &frac1.numerator);

    printf("Please enter an integer for the first denominator:\n");
    scanf("%d", &frac1.denominator);

    printf("Please enter an integer for the first numerator:\n");
    scanf("%d", &frac2.numerator);

    printf("Please enter an integer for the first denominator:\n");
    scanf("%d", &frac2.denominator);

    //  calculate the summation of the fractions
    struct fraction ans = fracSum(frac1, frac2);

    fracPrint(ans);

    return 0;

}

int gcd(int a, int b) {

    //  recursively find the gcd of the two denominators
    if(!b)
        return a;
    return gcd(b, a % b);

}

struct fraction fracSum(struct fraction frac1, struct fraction frac2) {

    //  fill the answer with base case data, assume fraction denominators are the same
    struct fraction ans = {.numerator = 0, .denominator = frac1.denominator};

    //  check if denominators are not the same
    if(frac1.denominator != frac2.denominator) {

        //  since fraction denominators are not the same, we have some calculations to do

        //  the new answer denominator can be found but doing frac1 * frac2 / gcd
        ans.denominator = frac1.denominator * frac2.denominator;
        ans.denominator /= gcd(frac1.denominator, frac2.denominator);

        //  now the numerators can be calculated
        //  for each fraction, the numerator can be found with the numerator * answer denominator / the fraction's denominator
        frac1.numerator *= ans.denominator / frac1.denominator;
        frac2.numerator *= ans.denominator / frac2.denominator;

    }

    //  now we can add the fraction numerators to get the answer numerator
    ans.numerator = frac1.numerator + frac2.numerator;

    return ans;

}

void fracPrint(struct fraction frac) {

    printf("fraction is: %d/%d\n", frac.numerator, frac.denominator);

}
