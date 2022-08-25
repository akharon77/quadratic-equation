#include "equations.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int solveSquare(const double a, const double b, const double c, double * const x1, double * const x2)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

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

int solveLinear(const double a, const double b, double *x)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));

    assert(x != NULL);

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
    assert(std::isfinite(n));

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

int getMode(int argc, const char *argv[])
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
