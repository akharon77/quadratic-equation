#include <stdio.h>
#include <math.h>
#include "equations.h"

int main()
{
    double a = NAN, b = NAN, c = NAN;

    printf("Input coefficients of quadratic equation ax^2 + bx + c = 0\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("Wrong input, try again\n");
        clear_input();
    }

    double x1 = NAN, x2 = NAN;

    int nSolutions = solveSquare(a, b, c, &x1, &x2);
    
    switch (nSolutions)
    {
        case 0: 
            printf("No solutions");
            break;
        case 1:
            printf("One solution:\n\tX = %lf", x1);
            break;
        case 2:
            printf("Two solutions\n\tX1 = %lf,\n\tX2 = %lf", x1, x2);
            break;
        case INF_SOLUTIONS:
            printf("Any number");
            break;
        default:
            printf("Error");
    }

    printf("\n");

    return 0;
}
