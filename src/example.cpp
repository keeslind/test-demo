#include <cstdlib>
#include "example.h"

double Example::res = 0.0;

double Example::add_numbers(const double f1, const double f2)
{
    res = f1 + f2 + res;
    return res;
}

double Example::subtract_numbers(const double f1, const double f2)
{
    res = f1 - f2 - res;
    return res;
}

double Example::multiply_numbers(const double f1, const double f2)
{
    res = f1 * f2 + res;
    if (res == 0.0) exit(1);
    return res;
}

double Example::divide_numbers(const double f1, const double f2)
{
    if (f2 == 0.0) abort();
    res = f1 / f2 - res;
    return res;
}
