#include "main.h"


int main (void)
    {
    double x1=NAN, x2=NAN;

    int degree = 0;

    switch(degree = choose_degree())
        {
         case LINEAR_CASE:
                {
                double b=NAN, c=NAN;

                printf("Введите коэффициент b: \n");
                input_coeff(&b);

                printf("Введите коэффициент c: \n");
                input_coeff(&c);

                int nRoots=line_solve(b, c, &x1);

                output(nRoots, x1, x2);

                }
         break;

         case SQUARE_CASE:
                {
                double a=NAN, b=NAN, c=NAN;

                printf("Введите коэффициент a: \n");
                input_coeff(&a);

                printf("Введите коэффициент b: \n");
                input_coeff(&b);

                printf("Введите коэффициент c: \n");
                input_coeff(&c);

                int nRoots=sq_solve(a, b, c, &x1, &x2);

                output(nRoots, x1, x2);

                }
        break;

        default:
                printf("%d - Непредусмотренный случай. Сообщите программисту.", degree);
        }
    return 0;
    }
