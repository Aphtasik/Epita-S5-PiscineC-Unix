#include <stdio.h>
#include "complex.h"
#include "complexe_print.h"
#include "complex_operations.h"

void print_complex(struct complex a)
{
    if (a.img > 0)
    {
        printf("complex(%.2f + %.2fi)\n");
    }
    a.img = - a.img;
    printf("complex(%.2f - %.2fi)\n");

 }
