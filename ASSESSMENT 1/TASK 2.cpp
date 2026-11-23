#include <stdio.h>
#include <limits.h>
#include <float.h>

/* The meter register is a 16-bit counter */
typedef unsigned short meter_t;

/* Function to calculate electricity consumption */
unsigned int consumption(meter_t previous, meter_t current)
{
    return (unsigned int)(meter_t)(current - previous);
}

int main(void)
{
    printf("===== DATA TYPE INFORMATION =====\n");

    printf("sizeof(meter_t) = %zu bytes\n", sizeof(meter_t));
    printf("Maximum reading = %u\n", (unsigned)USHRT_MAX);

    printf("\n===== METER CONSUMPTION =====\n");

    printf("Consumption: %u units\n",
           consumption(1200, 1530));

    printf("Consumption: %u units\n",
           consumption(65400, 120));

    printf("\n===== INTEGER LIMITS =====\n");

    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    printf("\n===== FLOAT LIMITS =====\n");

    printf("FLT_MAX = %e\n", FLT_MAX);
    printf("DBL_MAX = %e\n", DBL_MAX);

    return 0;
}
