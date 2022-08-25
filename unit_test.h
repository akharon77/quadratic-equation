#ifndef UNIT_TESTH
#define UNIT_TESTH

void testQuadraticAssert(double a, double b, double c, int ansCount, double ans1, double ans2, int count, double x1, double x2);
int testQuadraticManual(double a, double b, double c, int ansCount, double ans1, double ans2);

void testLinearAssert(const double a, const double b, const int ansCount, const double ans, const int count, const double x);
int testLinearManual(const double a, const double b, const int ansCount, const double ans);

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
