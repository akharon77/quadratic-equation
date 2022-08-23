#ifndef EQUATIONSH
#define EQUATIONSH

const double EPS = 1e-6;
enum {INF_SOLUTIONS = 42, ERROR_RET = -1};

int  solveSquare(double a, double b, double c, double *x1, double *x2);
int  solveLinear(double a, double b, double *x);
bool zeroEqual(double n);
int  sign(double n);
void clear_input();

#endif
