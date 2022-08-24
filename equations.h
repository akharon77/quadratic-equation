#ifndef EQUATIONSH
#define EQUATIONSH

const double EPS = 1e-6;
enum SOLUTIONS {ZERO_SOLUTIONS = 0, ONE_SOLUTION, TWO_SOLUTIONS, INF_SOLUTIONS = 42, ERROR_RET = -1};

int  solveSquare(double a, double b, double c, double *x1, double *x2);
int  solveLinear(double a, double b, double *x);

bool equal(double a, double b);
bool zeroEqual(double n);
int  sign(double n);

void clear_input();

void testQuadraticManual(double a, double b, double c, int ansCount, double ans1, double ans2);
void testAssert(double a, double b, double c, int ansCount, double ans1, double ans2, int count, double x1, double x2);

#endif
