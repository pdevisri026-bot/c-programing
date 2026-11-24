#include <stdio.h>

/* Tariff constants */
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

/* Function prototype */
long compute_bill(int units);

/* Function to calculate electricity bill */
long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS)
    {
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        units = SLAB2_UNITS;
    }

    if (units > SLAB1_UNITS)
    {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
        units = SLAB1_UNITS;
    }

    paise += (long)units * RATE1_PAISE;

    return paise;
}

/* Main function */
int main(void)
{
    int tests[] = {0, 100, 150, 200, 350};

    int n = sizeof(tests) / sizeof(tests[0]);

    printf("ELECTRICITY BILL CALCULATOR\n\n");

    for (int i = 0; i < n; i++)
    {
        long bill = compute_bill(tests[i]);

        printf("%3d units -> Rs %ld.%02ld\n",
               tests[i], bill / 100, bill % 100);
    }

    return 0;
}
