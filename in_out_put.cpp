#include "main.h"
#ifndef in_out_put
    #include "in_out_put.h"
#endif



int choose_degree(void)
    {
     int degree = 0;
     printf("Введите степень уравнения: \n");

     while (((degree = read_int()) == 0) || ((degree!=2) && (degree!=1)))
            {
            printf("Программа не может решить уравнение данной степени. Повторите ввод:\n");
            //if (degree == 0)
                //clear_buffer();
            }
     return degree;
    }


void input_coeff(double *coeff)
    {
    while (scanf("%lf", coeff) != 1)
        {
        clear_buffer();
        printf("Введённые данные некорректны. Повторите ввод\n");
        }
    clear_buffer();
    }


void clear_buffer(void)
    {
    int ch = NAN;
    while ((ch=getchar())!='\n');
    }


void output(int nRoots, double x1, double x2)
{
    switch(nRoots)
            {
            case ZERO_ROOTS:
                printf("Уравнение не имеет корней");
            break;
            case ONE_ROOT:
                printf("Уравнение имеет один корень х1 = %lf", x1);
            break;
            case TWO_ROOTS:
                printf("Уравнение имеет два корня х1 = %lf и x2 = %lf", x1, x2);
            break;
            default:
                printf("Уравнение имеет бесконечно много корней");
            break;
            }
}



int read_int(void)
    {
    int a = 0, n = 0;

    while ((a = getchar()) != '\n')
        {
        if (isdigit(a))
            {
            a = a -'0';
            n = n*10 + a;
            }
        else
            {
            clear_buffer();
            return 0;
            }
        }
    return n;
    }
