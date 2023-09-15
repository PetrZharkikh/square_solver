#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "in_out_put.h"
#include "compare.h"
#include "solvers.h"

#define in_out_put
#define compare
#define solvers

enum equation_cases
    {
    LINEAR_CASE=1,
    SQUARE_CASE=2
    };


enum number_of_roots
    {
    ZERO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOTS=2,
    INF_ROOTS=8
    };




