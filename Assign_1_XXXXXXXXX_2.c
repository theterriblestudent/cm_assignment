#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IntPartSqrt(int n) {
   int  x = n;
   int  y = floor((x + 1) / 2);
    while (y < x) {
        x = y;
        y = floor((x + floor(n / x)) / 2);
    }

    return x;
}

double FracPartSqrt(int n) {
    double x = IntPartSqrt(n);
    double function_x = x * x - n;
    double double_function_x = 2 * x;

    //We use precision 10^5
    const int PRECISION = 5;
    for (int i = 0; i < PRECISION; i++) {
        x = x - function_x / double_function_x;
        function_x = x * x - n;
        double_function_x = 2 * x;
    }

    return x - floor(x);
}

double Sqrt(int n) {
    return ((double)IntPartSqrt(n)) + FracPartSqrt(n);
}

int main() {
    printf("Input an integer: ");
    int number;
    scanf("%d", &number);
    printf("\nThe integer part of square root %d is %d.\nThe fraction part is %.5f.\nThe whole square root is %.5f\n", number,  IntPartSqrt(number), FracPartSqrt(number), Sqrt(number));
}