#include "main.h"

#ifndef in_out_put
    #include "compare.h"
#endif




const double EPS = 1E-10;

const int EQUALITY = 0;
const int MORE = 1;
const int LESS = -1;
const int NOT_EQUAL = -100000;


//--------------------------------------------------------------
//! compares two doubles
//!
//! @param [in] a first double value
//! @param [in] b second double value
//!
//!@return 0 in case of equality; 1 if first value > second value; 2 if first value < second value
//!
//--------------------------------------------------------------

int comp_d(double a, double b)
{
    if (fabs(a - b) < EPS)
        return EQUALITY;
    if  (a>b)
        return MORE;
    else
        return LESS;
}

//--------------------------------------------------------------
//! compares two NANs
//!
//! @param [in] a first NAN value
//! @param [in] b second NAN value
//!
//!@return 0 in case of equality; -100000 if first value not equal to second value
//!
//--------------------------------------------------------------

int is_nan_comp(double a, double b)
    {
    if (isnan(a) && isnan(b))
        return EQUALITY;
    else
        return NOT_EQUAL;
    }

//--------------------------------------------------------------
//! checks two doubles on a case of first number < second number
//!
//! @param [in] a first double value
//! @param [in] b second double value
//!
//!@return 1 in case of first number < second number; 0 in all other cases
//!
//--------------------------------------------------------------

int comp_d_less(double a, double b)
    {
    if (comp_d(a, b) == LESS)
        return 1;
    else
        return 0;
    }


//--------------------------------------------------------------
//! checks two doubles on a case of first number = second number
//!
//! @param [in] a first double value
//! @param [in] b second double value
//!
//!@return 1 in case of first number = second number; 0 in all other cases
//!
//--------------------------------------------------------------

int comp_d_equal(double a, double b)
    {
    if (comp_d(a, b) == EQUALITY)
        return 1;
    else
        return 0;
    }
