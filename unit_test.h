#ifndef UNIT_TESTH
#define UNIT_TESTH

#include <math.h>

struct quadraticTest {
    double a = NAN, b = NAN, c = NAN;
    int ansCount = 0;
    double ans1 = NAN, ans2 = NAN;
};

struct linearTest {
    double a = NAN, b = NAN;
    int ansCount = 0;
    double ans = NAN;
};

void testQuadraticAssert(const quadraticTest test, const int count, const double x1, const double x2);
int testQuadraticManual(const quadraticTest test);

void testLinearAssert(const linearTest test, const int count, const double x);
int testLinearManual(const linearTest test);

void testNumAndResAssert(const double n, const int ans, const int res);
int testZeroEqualManual(const double n, const bool ans);
int testSignManual(const double n, const int ans);

void testEqualAssert(const double a, const double b, const bool ans, const bool res);
int testEqualManual(const double a, const double b, const bool ans);

void testDone();

int testFromFileQuadratic();
int testFromFileLinear();
int testFromFileSign();
int testFromFileZeroEqual();
int testFromFileEqual();

#endif
