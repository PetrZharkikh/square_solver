#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "TXLib.h"


enum number_of_roots
    {
    ZERO_ROOTS=0,
    ONE_ROOT=1,
    TWO_ROOTS=2,
    INF_ROOTS=8
    };

enum equation_cases
    {
    LINEAR_CASE=1,
    SQUARE_CASE=2
    };

enum comparing_answers
    {
    EQUALITY=0,
    MORE=1,
    LESS=-1
    };

enum tests
    {
    TEST_NAME=10,
    NTESTS=6
    };


const double EPS=1E-10;


struct TestData
    {
    double a, b, c;
    double x1, x2;
    int nRoots;
    char T_name[TEST_NAME];
    };

TestData allData[] =
{{.a=0, .b=0,  .c=0, .x1=NAN,  .x2=NAN, .nRoots=INF_ROOTS,  "INF_ROOTS"},
{ .a=1, .b=0,  .c=0, .x1=0,    .x2=NAN, .nRoots=ONE_ROOT,   "ONE_ROOT"},
{ .a=1, .b=2,  .c=3, .x1=NAN,  .x2=NAN, .nRoots=ZERO_ROOTS, "NO_ROOTS"},
{ .a=0, .b=2,  .c=3, .x1=-1.5, .x2=NAN, .nRoots=ONE_ROOT,   "LINEAR"},
{ .a=1, .b=-4, .c=3, .x1=3,    .x2=1,   .nRoots=TWO_ROOTS,  "DEF_SQ"},
{ .a=2, .b=8,  .c=8, .x1=-2,   .x2=NAN, .nRoots=ONE_ROOT,   "D=0"}};


int TestOne(TestData data);

int sq_solve(double a,double b,double c, double  *x1, double  *x2);
int line_solve(double b, double c, double *x1);

int comp_d(double a, double b);
int comp_d_less(double a, double b);
int comp_d_equal(double a, double b);
int is_nan_comp(double a, double b);

void output_test_error(double x1, double x2, int nRoots,
                double x1ref, double x2ref, int nRootsref, const char * name);
void output(int nRoots, double x1, double x2);


int main(void)
    {
    for (unsigned int i=0; i < (sizeof(allData) / sizeof(allData[0])); i++)
        TestOne(allData[i]);

    return 0;
    }


int TestOne(TestData data)
    {
    double x1=NAN, x2=NAN;
    int nRoots = 0;

    nRoots = sq_solve(data.a, data.b, data.c, &x1, &x2);
    if ((!comp_d_equal(x1, data.x1)) ||
        (!comp_d_equal(x2, data.x2)) ||
        (nRoots != data.nRoots))
        {
        output_test_error(x1, x2, nRoots, data.x1, data.x2, data.nRoots, data.T_name);
        return 0;
        }
    else
        {
        printf("Тест в порядке\n");
        return 1;
        }
    }


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

        discrim= b*b - 4*a*c;

        if (comp_d_less(discrim, 0))
            {
            return ZERO_ROOTS;
            }
        if (comp_d_equal(discrim, 0))
            {
            *x1=(-b) / (2*a);
            if (comp_d_equal(*x1, 0))
                *x1=0;
            return ONE_ROOT;
            }
        sqrt_discrim=sqrt(discrim);
        *x1= (-b + sqrt_discrim) / (2*a);
        *x2= (-b - sqrt_discrim) / (2*a);
        return TWO_ROOTS;

        }
    }


int line_solve(double b, double c, double *x1)
    {
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1!=NULL);

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
    else
        {
        *x1 = -c / b;
        return ONE_ROOT;
        }
    }


int comp_d(double a, double b)
    {
    if (!isfinite(a) || !isfinite(b))
        return is_nan_comp(a, b);
    else
        {
        assert(isfinite(a));
        assert(isfinite(b));
        if (fabs(a - b) < EPS)
            return EQUALITY;
        if  (a>b)
            return MORE;
        else
            return LESS;
        }
    }


int comp_d_less(double a, double b)
    {
    if (comp_d(a, b) == LESS)
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


int is_nan_comp(double a, double b)
    {
    if (isnan(a) && isnan(b))
        return EQUALITY;
    else
        return 0;
    }


void output_test_error(double x1, double x2, int nRoots,
                       double x1ref, double x2ref, int nRootsref, const char * name)
    {
    printf("Тест %s выдал ошибку.\n", name);
    printf("Ожидалось:\n");
    output(nRootsref, x1ref, x2ref);
    printf("Получилось:\n");
    output(nRoots, x1, x2);
    }


void output(int nRoots, double x1, double x2)
    {
    switch(nRoots)
            {
            case ZERO_ROOTS:
                printf("Уравнение не имеет корней\n");
            break;

            case ONE_ROOT:
                printf("Уравнение имеет один корень х1 = %lf\n", x1);
            break;

            case TWO_ROOTS:
                printf("Уравнение имеет два корня х1 = %lf и x2 = %lf\n", x1, x2);
            break;

            case INF_ROOTS:
                printf("Уравнение имеет бесконечно много корней\n");
            break;

            default:
                printf("Уравнение имеет странное количество корней. Перепроверьте введённые данные\n");
            break;
            }
    }
