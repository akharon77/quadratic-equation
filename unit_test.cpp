#include "equations.h"
#include <math.h>
#include <stdio.h>

int countOfTests = 0;

void testAssert(double a, double b, double c, int ansCount, double ans1, double ans2, int count, double x1, double x2)
{
    printf("TEST #%d - a = \t%lf, b = \t%lf, c = \t%lf\n"
            "FAILED: count of roots = %d, x1 = %lf, x2 = %lf\n"
            "EXPECTED: count of roots = %d, x1 = %lf, x2 = %lf\n\n",
            countOfTests,
            a, b, c,
            count,    x1,   x2,
            ansCount, ans1, ans2);
}

void testQuadraticManual(double a, double b, double c, int ansCount, double ans1, double ans2)
{
    ++countOfTests;
    double x1 = NAN, x2 = NAN;
    int nSolutions = solveSquare(a, b, c, &x1, &x2);
    if (ansCount != nSolutions                                  ||
        (ansCount == 0 && !(std::isnan(x1) && std::isnan(x2)))  ||
        (ansCount == 1 && !equal(x1, ans1))                     ||
        (ansCount == 2 && !(equal(x1, ans1) && equal(x2, ans2))))
    {
        testAssert(a, b, c, ansCount, ans1, ans2, nSolutions, x1, x2);
    }
}

