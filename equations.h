#ifndef EQUATIONSH
#define EQUATIONSH

const double EPS = 1e-6;
enum SOLUTIONS
{
    ZERO_SOLUTIONS, 
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INF_SOLUTIONS = 42,
    ERROR_RET = -1
};

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
int  solveSquare(double a, double b, double c, double *x1, double *x2);

/*!
 * Solve linear equation
 *
 * \param[in] a Coefficient of x
 * \param[in] b Free term
 * \param[out] x Solution if exist
 *
 * \return Count of solutions
 */
int  solveLinear(double a, double b, double *x);

/*!
 * Checks two numbers for equality taking into account the error
 *
 * \return true if equal else false
 */
bool equal(double a, double b);

/*!
 * Checks if the number is equal to zero taking into account the error
 *
 * \return true if zero, else false
 */
bool zeroEqual(double n);

/*!
 * Return sign of number taking into account the error
 *
 * \return -1 if negative, 0 if zero, 1 if positive
 */
int  sign(double n);

/*!
 * Clear buffer of stdin
 */
void clear_input();

void testQuadraticManual(double a, double b, double c, int ansCount, double ans1, double ans2);
void testAssert(double a, double b, double c, int ansCount, double ans1, double ans2, int count, double x1, double x2);

#endif
