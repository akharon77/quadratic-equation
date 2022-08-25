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

enum PROGRAM_MODES
{
    TEST_FORCE_MODE,
    TEST_FILE_MODE,
    RUN_MODE,
    ERROR_MODE
};

const int NMODES = 3;
const struct MODE
{
    const char *strForm;
    int modeID;
} MODES[] = 
    {
        {"--test-force", TEST_FORCE_MODE},
        {"--test-file",  TEST_FILE_MODE},
        {"--run",        RUN_MODE}
    };

/*!
 * Starts forced unit-tests for program
 */
void testForce();

/*!
 * Starts unit-test for program from test-files
 */
void testFromFile();

/*!
 * Run main program for solving equation
 */
void run();

/*!
 * Shows mode for program
 *
 * \return RUN_MODE, TEST_FORCE_MODE or TEST_FILE_MODE in right case else ERROR_MODE
 */
int getMode(const int argc, const char *argv[]);

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
int  solveSquare(const double a, const double b, const double c, double * const x1, double * const x2);

/*!
 * Solve linear equation
 *
 * \param[in] a Coefficient of x
 * \param[in] b Free term
 * \param[out] x Solution if exist
 *
 * \return Count of solutions
 */
int  solveLinear(const double a, const double b, double * const x);

/*!
 * Checks two numbers for equality taking into account the error
 *
 * \return true if equal else false
 */
bool equal(const double a, const double b);

/*!
 * Checks if the number is equal to zero taking into account the error
 *
 * \return true if zero, else false
 */
bool zeroEqual(const double n);

/*!
 * Return sign of number taking into account the error
 *
 * \return -1 if negative, 0 if zero, 1 if positive
 */
int  sign(const double n);

/*!
 * Clear buffer of stdin
 *
 * \return true if buffer was filled by spaces and etc else false
 */
bool clear_input();

#endif
