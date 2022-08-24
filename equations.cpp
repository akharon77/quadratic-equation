#include "equations.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

/*!
 * Solve quadratic equation
 *
 * \param[in] a Coefficient of x^2
 * \param[in] b Coefficient of x
 * \param[in] c Free term
 * \param[out] x1 First solution if exist
 * \param[out] x2 Second solution if exist
 * 
 * \return Count of solutions
 */
int solveSquare(double a, double b, double c, double *x1, double *x2)
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
            return 0;
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
            return 2;
        }
        else
        {
            *x1 = -b / (2 * a);
            return 1;
        }
    }

    return ERROR_RET;
}

/*!
 * Solve linear equation
 *
 * \param[in] a Coefficient of x
 * \param[in] b Free term
 * \param[out] x Solution if exist
 *
 * \return Count of solutions
 */
int solveLinear(double a, double b, double *x)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));

    assert(x != NULL);

    if (zeroEqual(a))
    {
        return zeroEqual(b) ? INF_SOLUTIONS : 0;
    }
    else
    {
        *x = -b / a;
        return 1;
    }

    return ERROR_RET;
}

/*!
 * Clear buffer of stdin
 */
void clear_input()
{
    int temp = '\0';
    do
    {
        temp = getchar();
    }
    while (temp != '\n' && temp != EOF);
}

/*!
 * Return sign of number taking into account the error
 *
 * \return -1 if negative, 0 if zero, 1 if positive
 */
int sign(double n)
{
    assert(std::isfinite(n));

    if (n < -EPS)
        return -1;
    else if (n > EPS)
        return 1;
    return 0;
}

/*!
 * Checks two numbers for equality taking into account the error
 *
 * \return true if equal else false
 */
bool equal(double a, double b)
{
    return a - EPS < b && b < a + EPS;
}

/*!
 * Checks if the number is equal to zero taking into account the error
 *
 * \return true if zero, else false
 */
bool zeroEqual(double n)
{
    return !sign(n);
}
