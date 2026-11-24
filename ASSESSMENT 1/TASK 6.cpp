#include <stdio.h>

/* Tariff constants */
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

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
    int units;
    long bill;

    printf("ELECTRICITY BILL CALCULATOR\n");

    printf("Enter electricity units consumed: ");

    /* Check whether input is valid */
    if (scanf("%d", &units) != 1)
    {
        printf("Error: Invalid input! Please enter a number.\n");
        return 1;
    }

    if (units < 0)
    {
        printf("Error: Units cannot be negative.\n");
        return 1;
    }

    /* Calculate bill */
    bill = compute_bill(units);

    /* Display bill */
    printf("\n----- ELECTRICITY BILL -----\n");
    printf("Units consumed : %d\n", units);
    printf("Total bill     : Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
