#include <stdio.h>
#include <math.h>
#include "equations.h"
#include "unit_test.h"

int main(int argc, const char *argv[])
{
    int mode = getMode(argc, argv);
    if (mode == TEST_FORCE_MODE)
        testForce();
    else if (mode == TEST_FILE_MODE)
        testFromFile();
    else if (mode == RUN_MODE)
        run();
    else
        printf(RED "Wrong program arguments\n" NORMAL);
    return 0;
}

void run()
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    
    input(&a, &b, &c);

    int nSolutions = solveSquare(a, b, c, &x1, &x2);
    
    output(nSolutions, x1, x2);
}
