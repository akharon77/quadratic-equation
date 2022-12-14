#include "equations.h"
#include "unit_test.h"
#include "colors.h"
#include <math.h>
#include <stdio.h>

#define TEST_DIR "./tests/"

int countOfTests = 0;

void testForce()
{
    int countTestsDone =
          testQuadraticManual({ 1,  1,  1, ZERO_SOLUTIONS, NAN,    NAN})
        + testQuadraticManual({ 1,  0,  1, ZERO_SOLUTIONS, NAN,    NAN})
        + testQuadraticManual({-1, -1,  0, TWO_SOLUTIONS,  -1,     0  })
        + testQuadraticManual({ 1,  2,  1, ONE_SOLUTION,   -1,     NAN})
        + testQuadraticManual({ 0,  0,  0, INF_SOLUTIONS,  NAN,    NAN})
        + testQuadraticManual({ 0,  1,  2, ONE_SOLUTION,   -2,     NAN})
        + testQuadraticManual({ 0,  5,  2, ONE_SOLUTION,   -0.4,   NAN})
        + testQuadraticManual({ 0,  0,  1, ZERO_SOLUTIONS, NAN,    NAN})

        + testLinearManual   ({ 0,  0,     INF_SOLUTIONS,  NAN        })
        + testLinearManual   ({ 1,  1,     ONE_SOLUTION,   -1         })
        + testLinearManual   ({-1,  2,     ONE_SOLUTION,   2          })
        + testLinearManual   ({ 0,  1,     ZERO_SOLUTIONS, NAN        })

        + testSignManual(    4.4,  1)
        + testSignManual(   -4.5, -1)
        + testSignManual(   -0.5, -1)
        + testSignManual(    0.5,  1)
        + testSignManual(      0,  0)
        + testSignManual(0.00001,  1)

        + testZeroEqualManual(     1, 0)
        + testZeroEqualManual(     3, 0)
        + testZeroEqualManual( 0.001, 0)
        + testZeroEqualManual(-0.001, 0)
        + testZeroEqualManual(   -11, 0)

        + testEqualManual(     1,     2, 0)
        + testEqualManual(-0.001,     0, 0)
        + testEqualManual(     1,    -3, 0)
        + testEqualManual(   100, 0.001, 0)
        + testEqualManual(    -1, -2.01, 0)
        + testEqualManual(     1,     1, 1)
        + testEqualManual(    -1,    -1, 1);

    printf(BOLD "%d tests done\n" NORMAL, countTestsDone);
}

void testFromFile()
{
    int countTestsDone = 
          testFromFileQuadratic()
        + testFromFileLinear()
        + testFromFileSign()
        + testFromFileZeroEqual()
        + testFromFileEqual();

    printf(BOLD "%d tests done\n" NORMAL, countTestsDone);
}

int testFromFileQuadratic()
{
    FILE *fin = fopen(TEST_DIR "quadratic_tests.txt", "r");
    if (fin == NULL)
        return 0;
    quadraticTest test;
    int testCount = 0;
    int res = 0;
    if (fscanf(fin, "%d", &testCount) == EOF)
        return 0;
    for (int i = 0; i < testCount; ++i)
    {
        if (fscanf(fin, "%lf %lf %lf %d %lf %lf", &test.a, &test.b, &test.c, &test.ansCount, &test.ans1, &test.ans2) == EOF)
        {
            printf(RED "Quadratic tests - error in reading file\n" NORMAL);
            return res;
        }
        res += testQuadraticManual(test);
    }
    fclose(fin);
    return res;
}

int testFromFileLinear()
{
    FILE *fin = fopen(TEST_DIR "linear_tests.txt", "r");
    if (fin == NULL)
        return 0;
    linearTest test;
    int testCount = 0;
    int res = 0;
    if (fscanf(fin, "%d", &testCount) == EOF)
        return 0;
    for (int i = 0; i < testCount; ++i)
    {
        if(fscanf(fin, "%lf %lf %d %lf", &test.a, &test.b, &test.ansCount, &test.ans) == EOF) {
            printf(RED "Linears tests - file reading error\n" NORMAL);
            return res;
        }
        res += testLinearManual(test);
    }
    fclose(fin);
    return res;
}

int testFromFileSign()
{
    FILE *fin = fopen(TEST_DIR "sign_tests.txt", "r");
    if (fin == NULL)
        return 0;
    double n = NAN;
    int ans = 0;
    int testCount = 0;
    int res = 0;
    if (fscanf(fin, "%d", &testCount) == EOF)
        return 0;
    for (int i = 0; i < testCount; ++i)
    {
        if (fscanf(fin, "%lf %d", &n, &ans) == EOF)
        {
            printf(RED "Sign tests - file reading error\n" NORMAL);
            return res;
        }
        res += testSignManual(n, ans);
    }
    fclose(fin);
    return res;
}

int testFromFileZeroEqual()
{
    FILE *fin = fopen(TEST_DIR "zero_equal_tests.txt", "r");
    if (fin == NULL)
        return 0;
    double n = NAN;
    int ans = 0;
    int testCount = 0;
    int res = 0;
    if (fscanf(fin, "%d", &testCount) == EOF)
        return 0;
    for (int i = 0; i < testCount; ++i)
    {
        if (fscanf(fin, "%lf %d", &n, &ans) == EOF)
        {
            printf(RED "Zero equal tests - file reading error\n" NORMAL);
            return res;
        }
        res += testZeroEqualManual(n, ans);
    }
    fclose(fin);
    return res;
}

int testFromFileEqual()
{
    FILE *fin = fopen(TEST_DIR "equal_tests.txt", "r");
    if (fin == NULL)
        return 0;
    double a = NAN, b = NAN;
    int ans = 0;
    int testCount = 0;
    int res = 0;
    if (fscanf(fin, "%d", &testCount) == EOF)
        return 0;
    for (int i = 0; i < testCount; ++i)
    {
        if (fscanf(fin, "%lf %lf %d", &a, &b, &ans) == EOF)
        {
            printf(RED "Equal tests - file reading error\n" NORMAL);
            return res;
        }
        res += testEqualManual(a, b, ans);
    }
    fclose(fin);
    return res;
}
void testQuadraticAssert(const quadraticTest test, const int count, const double x1, const double x2)
// void testQuadraticAssert(const double a, const double b, const double c, const int ansCount, const double ans1, const double ans2, const int count, const double x1, const double x2)
{
    double a = test.a, b = test.b, c = test.c;
    double ans1 = test.ans1, ans2 = test.ans2;
    int ansCount = test.ansCount;
    printf(RED "TEST #%d - a = \t%lf, b = \t%lf, c = \t%lf\n"
            "FAILED: count of roots = %d, x1 = %lf, x2 = %lf\n"
            "EXPECTED: count of roots = %d, x1 = %lf, x2 = %lf\n" NORMAL,
            countOfTests, a, b, c,
            count,    x1,   x2,
            ansCount, ans1, ans2);
}

int testQuadraticManual(const quadraticTest test)
// int testQuadraticManual(const double a, const double b, const double c, const int ansCount, const double ans1, const double ans2)
{
    ++countOfTests;
    double x1 = NAN, x2 = NAN;
    double a = test.a, b = test.b, c = test.c;
    double ans1 = test.ans1, ans2 = test.ans2;
    int ansCount = test.ansCount;
    int nSolutions = solveSquare(a, b, c, &x1, &x2);
    if (ansCount != nSolutions                                                  ||
        (ansCount == ZERO_SOLUTIONS && !(std::isnan(x1) && std::isnan(x2)))     ||
        (ansCount == ONE_SOLUTION && !(equal(x1, ans1) && std::isnan(x2)))      ||
        (ansCount == TWO_SOLUTIONS && !(equal(x1, ans1) && equal(x2, ans2))))
    {
        testQuadraticAssert(test, nSolutions, x1, x2);
        return 0;
    }
    testDone();
    return 1;
}

void testLinearAssert(const linearTest test, const int count, const double x)
// void testLinearAssert(const double a, const double b, const int ansCount, const double ans, const int count, const double x)
{
    double a = test.a, b = test.b;
    double ans = test.ans;
    int ansCount = test.ansCount;
    printf(RED "TEST #%d - a = %lf, b = \t%lf\n"
            "FAILED: count of roots = %d, x = %lf\n"
            "EXPECTED: count of roots = %d, x = %lf\n" NORMAL,
            countOfTests, a, b,
            count,    x,
            ansCount, ans);
}

int testLinearManual(const linearTest test)
// int testLinearManual(const double a, const double b, const int ansCount, const double ans)
{
    double a = test.a, b = test.b;
    double ans = test.ans;
    int ansCount = test.ansCount;
    ++countOfTests;
    double x = NAN;
    int nSolutions = solveLinear(a, b, &x);
    if (ansCount != nSolutions                              ||
        (ansCount == ZERO_SOLUTIONS && !std::isnan(x))      ||
        (ansCount == ONE_SOLUTION && !equal(x, ans)))
    {
        testLinearAssert(test, nSolutions, x);
        return 0;
    }
    testDone();
    return 1;
}

void testNumAndResAssert(const double n, const int ans, const int res)
{
    printf(RED "TEST #%d - n = %lf\n"
            "FAILED: ans = %d\n"
            "EXPECTED: ans = %d\n" NORMAL,
            countOfTests, n,
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
    printf(RED "TEST #%d - a = %lf, b = %lf\t\n"
            "FAILED: ans = %d\n"
            "EXPECTED: ans = %d\n" NORMAL,
            countOfTests, a, b,
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
    printf(GREEN "TEST #%d \t- DONE\n" NORMAL, countOfTests);
}
