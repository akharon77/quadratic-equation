#include <stdio.h>
#include <math.h>
#include "equations.h"
#include "unit_test.h"

int main(int argc, const char *argv[])
{
    int mode = getMode(argc, argv);
    if (mode == TEST_FORCE_MODE)
        testForce();
    else if (mode == TEST_FILE_MODE)
        testFromFile();
    else if (mode == RUN_MODE)
        run();
    else
        printf("\x1b[31mWrong program arguments\n\x1b[0m");
    return 0;
}

void run()
{
    double a = NAN, b = NAN, c = NAN;

    printf("Input coefficients of quadratic equation ax^2 + bx + c = 0\n");
    while (true)
    {
        int nInput = scanf("%lf %lf %lf", &a, &b, &c);
        bool flag = clear_input();
        if (nInput == 3 && flag)
            break;
        printf("Wrong input, try again\n");
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
}
