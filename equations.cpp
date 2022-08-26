#include "equations.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

int solveSquare(const double a, const double b, const double c, double * const x1, double * const x2)
{
    ASSERT(isfinite(a));
    ASSERT(isfinite(b));
    ASSERT(isfinite(c));

    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);

    *x1 = *x2 = NAN;

    if (zeroEqual(a))
    {
        return solveLinear(b, c, x1);
    }
    else
    {
        double D = b*b - 4*a*c;

        if (sign(D) < 0)
        {
            return ZERO_SOLUTIONS;
        }
        else if (sign(D) > 0)
        {
            double sqrt_D = sqrt(D);
            *x1 = 0. + (-b - sqrt_D) / (2 * a);
            *x2 = 0. + (-b + sqrt_D) / (2 * a);
            if (*x1 > *x2)
            {
                double buf = *x1;
                *x1 = *x2;
                *x2 = buf;
            }
            return TWO_SOLUTIONS;
        }
        else
        {
            *x1 = -b / (2 * a);
            return ONE_SOLUTION;
        }
    }

    return ERROR_RET;
}

int solveLinear(const double a, const double b, double * const x)
{
    ASSERT(isfinite(a));
    ASSERT(isfinite(b));

    ASSERT(x != NULL);

    *x = NAN;

    if (zeroEqual(a))
    {
        return zeroEqual(b) ? INF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else
    {
        *x = -b / a;
        return ONE_SOLUTION;
    }

    return ERROR_RET;
}

bool clear_input()
{
    bool isSpace = true;
    int temp = '\0';
    do
    {
        temp = getchar();
        if (temp != ' ' && temp != '\t' && temp != '\n')
            isSpace = false;
    }
    while (temp != '\n' && temp != EOF);
    return isSpace;
}

int sign(const double n)
{
    ASSERT(isfinite(n));

    if (n < -EPS)
        return -1;
    else if (n > EPS)
        return 1;
    return 0;
}

bool equal(const double a, const double b)
{
    return a - EPS < b && b < a + EPS;
}

bool zeroEqual(const double n)
{
    return !sign(n);
}

int getMode(const int argc, const char *argv[])
{
    int retMode = ERROR_MODE;
    if (argc == 1)
        return RUN_MODE;
    else
        for (int i = 1; i < argc; ++i)
            for (int j = 0; j < NMODES; ++j)
                if (strcmp(MODES[j].strForm, argv[i]) == 0)
                {
                    if (retMode != ERROR_MODE)
                        return ERROR_MODE;
                    else
                        retMode = MODES[j].modeID;
                }
    return retMode;
}

void input(double * const a, double * const b, double * const c)
{
    printf("Input coefficients of quadratic equation ax^2 + bx + c = 0\n");
    while (true)
    {
        int nInput = scanf("%lf %lf %lf", a, b, c);
        bool flag = clear_input();
        if (nInput == 3 && flag)
            break;
        printf("Wrong input, try again\n");
    }
}

void output(const int count, const double x1, const double x2)
{
    switch (count)
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
