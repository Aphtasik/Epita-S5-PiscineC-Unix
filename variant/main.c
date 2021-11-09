#include "variant.h"

int main()
{
    union type_any ta = 
    {
        .int_v = 0,
    };
    struct variant a =
    {
        .type = TYPE_INT,
        .type_any = ta,
    };
    return 0;
}
