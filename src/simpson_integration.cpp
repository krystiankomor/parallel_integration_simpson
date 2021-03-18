#include "simpson_integration.h"
#include <omp.h>

SimpsonIntegration::SimpsonIntegration(double a, double b, double c, double x1, double x2, int n, int p) 
    : a(a), b(b), c(c), x1(x1), x2(x2), n(n) {
        omp_set_num_threads(p);
        dx = (x2 - x1) / n;
}

double SimpsonIntegration::integrationFunction(double number) {
    return (a * number * number) + (b * number) + c;
}

void SimpsonIntegration::count() {
    double firstNumberFunctionValue = integrationFunction(x1);
    double lastNumberFunctionValue = integrationFunction(x2);

    s = countS(dx);
    st = countSt(dx);
    result = dx / 6 * (firstNumberFunctionValue + lastNumberFunctionValue + 2 * s + 4 * st);
}

double SimpsonIntegration::countX(double x, int i, double dx) {
    return x + i * dx;
}

double SimpsonIntegration::countS(double dx) {
    double s = 0;

    #pragma omp parallel for reduction(+:s)
    for(int i = 1; i < n; i++)
    {
        s += integrationFunction(countX(x1, i, dx));
    }

    return s;
}

double SimpsonIntegration::countSt(double dx) {
    double st = 0;

    #pragma omp parallel for reduction(+:st)
    for(int i = 1; i <= n; i++)
    {
        double x = countX(x1, i, dx);
        st += integrationFunction(x - dx / 2);
    }

    return st;
}

double SimpsonIntegration::getResult() {
    return result;
}