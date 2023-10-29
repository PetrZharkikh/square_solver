#include "main.h"

#ifndef in_out_put
    #include "solvers.h"
#endif

extern const double EPS = 1E-10;


//-------------------------------------------------------------
//! Solves a linear equation bx + c = 0
//!
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 pointer to the 1st root
//!
//!@return number of roots
//!
//!@note in case of infinite number of roots, returns INF_ROOTS
//-------------------------------------------------------------

int line_solve(double b, double c, double *x1)    //extern
    {
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);

    if (comp_d_less(fabs(b), EPS))
        {
        if (comp_d_less(fabs(c), EPS))
            {
            return INF_ROOTS;
            }
        else
            {
            return ZERO_ROOTS;
            }
        }
    *x1 = -c / b;
    return ONE_ROOT;
    }

//-------------------------------------------------------------
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 pointer to the 1st root
//! @param [out] x2 pointer to the 2nd root
//!
//!@return number of roots
//!
//!@note when a-coefficient is zero, calls line_solve function
//-------------------------------------------------------------

int sq_solve(double a, double b, double c, double* x1, double* x2)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1!=NULL);
    assert(x2!=NULL);

    if (comp_d_less(fabs(a), EPS))
        return line_solve(b,c,x1);

    else
        {
        double discrim=NAN, sqrt_discrim=NAN;

        discrim = b*b - 4*a*c;

        if (comp_d_less(discrim, 0))
            {
            return ZERO_ROOTS;
            }
        if (comp_d_equal(discrim, 0))
            {
            *x1 = (-b) / (2*a);
            if (comp_d_equal(*x1, 0))
                *x1 = 0;
            return ONE_ROOT;
            }
        sqrt_discrim=sqrt(discrim);
        *x1= (-b + sqrt_discrim) / (2*a);
        *x2= (-b - sqrt_discrim) / (2*a);
        return TWO_ROOTS;

        }
    }
