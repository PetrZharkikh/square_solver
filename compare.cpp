#include "main.h"
#include "compare.h"



const double EPS=1E-10;

const int EQUALITY=0;
const int MORE=1;
const int LESS=-1;


int comp_d(double a, double b)
{
    if (fabs(a - b) < EPS)
        return EQUALITY;
    if  (a>b)
        return MORE;
    else
        return LESS;
}


int is_nan_comp(double a, double b)
    {
    if (isnan(a) && isnan(b))
        return EQUALITY;
    else
        return 0;
    }


int comp_d_less(double a, double b)
    {
    if (comp_d(a, b)==LESS)
        return 1;
    else
        return 0;
    }


int comp_d_equal(double a, double b)
    {
    if (comp_d(a, b) == EQUALITY)
        return 1;
    else
        return 0;
    }
