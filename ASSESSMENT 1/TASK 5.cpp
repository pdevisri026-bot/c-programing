
#ifndef BILLING_H
#define BILLING_H

/* Tariff constants */
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

/* Function prototypes */
long compute_bill(int units);

#endif

#include <stdio.h>
#include "billing.h"

/* Function to calculate electricity bill */
long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

#ifdef DEBUG
    printf("DEBUG: Initial fixed charge = %ld paise\n", paise);
    printf("DEBUG: Units consumed = %d\n", units);
#endif

    if (units > SLAB2_UNITS)
    {
        paise += (units - SLAB2_UNITS) * RATE3_PAISE;
        units = SLAB2_UNITS;
    }

    if (units > SLAB1_UNITS)
    {
        paise += (units - SLAB1_UNITS) * RATE2_PAISE;
        units = SLAB1_UNITS;
    }

    paise += units * RATE1_PAISE;

#ifdef DEBUG
    printf("DEBUG: Final bill = %ld paise\n", paise);
#endif

    return paise;
}

/* Main function */
int main(void)
{
    int units[] = {0, 100, 150, 200, 350};
    int n = sizeof(units) / sizeof(units[0]);

    for (int i = 0; i < n; i++)
    {
        long bill = compute_bill(units[i]);

        printf("%d units -> Rs %ld.%02ld\n",
               units[i], bill / 100, bill % 100);
    }

    return 0;
}
