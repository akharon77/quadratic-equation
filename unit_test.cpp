#include "equations.h"
#include <math.h>
#include <stdio.h>

int countOfTests = 0;

void testQuadraticAssert(const double a, const double b, const double c, const int ansCount, const double ans1, const double ans2, const int count, const double x1, const double x2)
{
    printf("\x1b[31mTEST #%d - a = \t%lf, b = \t%lf, c = \t%lf\n"
            "FAILED: count of roots = %d, x1 = %lf, x2 = %lf\n"
            "EXPECTED: count of roots = %d, x1 = %lf, x2 = %lf\n\x1b[0m",
            countOfTests,
            a, b, c,
            count,    x1,   x2,
            ansCount, ans1, ans2);
}

int testQuadraticManual(const double a, const double b, const double c, const int ansCount, const double ans1, const double ans2)
{
    ++countOfTests;
    double x1 = NAN, x2 = NAN;
    int nSolutions = solveSquare(a, b, c, &x1, &x2);
    if (ansCount != nSolutions                                                  ||
        (ansCount == ZERO_SOLUTIONS && !(std::isnan(x1) && std::isnan(x2)))     ||
        (ansCount == ONE_SOLUTION && !(equal(x1, ans1) && std::isnan(x2)))      ||
        (ansCount == TWO_SOLUTIONS && !(equal(x1, ans1) && equal(x2, ans2))))
    {
        testQuadraticAssert(a, b, c, ansCount, ans1, ans2, nSolutions, x1, x2);
        return 0;
    }
    testDone();
    return 1;
}

void testLinearAssert(const double a, const double b, const int ansCount, const double ans, const int count, const double x)
{
    printf("\x1b[31mTEST #%d - a = %lf, b = \t%lf\n"
            "FAILED: count of roots = %d, x = %lf\n"
            "EXPECTED: count of roots = %d, x = %lf\n\x1b[0m",
            countOfTests,
            a, b,
            count,    x,
            ansCount, ans);
}

int testLinearManual(const double a, const double b, const int ansCount, const double ans)
{
    ++countOfTests;
    double x = NAN;
    int nSolutions = solveLinear(a, b, &x);
    if (ansCount != nSolutions                              ||
        (ansCount == ZERO_SOLUTIONS && !std::isnan(x))      ||
        (ansCount == ONE_SOLUTION && !equal(x, ans)))
    {
        testLinearAssert(a, b, ansCount, ans, nSolutions, x);
        return 0;
    }
    testDone();
    return 1;
}

void testNumAndResAssert(const double n, const int ans, const int res)
{
    printf("\x1b[31mTEST #%d - n = %lf\n"
            "FAILED: ans = %d\n"
            "EXPECTED: ans = %d\n\x1b[0m",
            countOfTests,
            n,
            res, ans);
}

int testSignManual(const double n, const int ans)
{
    ++countOfTests;
    int res = sign(n);
    if (res != ans)
    {
        testNumAndResAssert(n, ans, res);
        return 0;
    }
    testDone();
    return 1;
}

int testZeroEqualManual(const double n, const bool ans)
{
    ++countOfTests;
    bool res = zeroEqual(n);
    if (res != ans)
    {
        testNumAndResAssert(n, ans, res);
        return 0;
    }
    testDone();
    return 1;
}

void testEqualAssert(const double a, const double b, const bool ans, const bool res)
{
    printf("\x1b[31mTEST #%d - a = %lf, b = %lf\t\n"
            "FAILED: ans = %d\n"
            "EXPECTED: ans = %d\n\x1b[0m",
            countOfTests,
            a, b,
            res, ans);
}

int testEqualManual(const double a, const double b, const bool ans)
{
    ++countOfTests;
    bool res = equal(a, b);
    if (res != ans)
    {
        testEqualAssert(a, b, ans, res);
        return 0;
    }
    testDone();
    return 1;
}

void testDone()
{
    printf("\x1b[32mTEST #%d \t- DONE\n\x1b[0m", countOfTests);
}
