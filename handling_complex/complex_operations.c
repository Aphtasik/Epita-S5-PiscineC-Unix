#include <stdio.h>
#include "complex.h"
#include "complexe_print.h"
#include "complex_operations.h"

struct complex neg_complex(struct complex a)
{
    a.img = - a.img;
    a.real = - a.real;

    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    a.img += b.img;
    a.real += b.real;
    return a;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    a.img -= b.img;
    a.real -= b.real;
    return a;

}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex c = 
    {
        .real = (a.real * b.real) - (a.img * b.img),
        .img = (a.real * b.img) + (a.img * b.real);
    };
    return c;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float denom = b.real * b.real + b.img * b.img;
    struct complex c =
    {
        .real = (a.real * b.real + a.img * b.img) / denom,
        .img = (a.img * b.real - a.real * b.img) / denom
    };
    return c;
}
