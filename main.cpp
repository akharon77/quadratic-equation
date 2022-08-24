#include <stdio.h>
#include <math.h>
#include "equations.h"

int main()
{

#ifdef _DEBUG
    testQuadraticManual( 1,  1,  1, ZERO_SOLUTIONS, NAN,    NAN);
    testQuadraticManual( 1,  0,  1, ZERO_SOLUTIONS, NAN,    NAN);
    testQuadraticManual(-1, -1,  0, TWO_SOLUTIONS,  -1,     0);
    testQuadraticManual( 1,  2,  1, ONE_SOLUTION,   -1,     NAN);
    testQuadraticManual( 0,  0,  0, INF_SOLUTIONS,  NAN,    NAN);
    testQuadraticManual( 0,  1,  2, ONE_SOLUTION,   -2,     NAN);
    testQuadraticManual( 0,  5,  2, ONE_SOLUTION,   -0.4,   NAN);
    testQuadraticManual( 0,  0,  1, ZERO_SOLUTIONS, NAN,    NAN);
#endif

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
        case ZERO_SOLUTIONS: 
            printf("No solutions");
            break;
        case ONE_SOLUTION:
            printf("One solution:\n\tX = %lf", x1);
            break;
        case TWO_SOLUTIONS:
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
