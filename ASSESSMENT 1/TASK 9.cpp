
#include <stdio.h>

#define MAX_READING 65535
#define ROLLOVER_VALUE 65536

#define RATE1 1.50
#define RATE2 2.50
#define RATE3 4.00

double calculateBill(unsigned int units)
{
    double bill = 0.0;

    if (units <= 100)
    {
        bill = units * RATE1;
    }
    else if (units <= 200)
    {
        bill = (100 * RATE1) +
               ((units - 100) * RATE2);
    }
    else
    {
        bill = (100 * RATE1) +
               (100 * RATE2) +
               ((units - 200) * RATE3);
    }

    return bill;
}

int main()
{
    unsigned int previous, current, units;
    unsigned int totalUnits;
    double bill, totalBill = 0.0;
    int i, n;

    printf("ELECTRICITY BILLING SYSTEM\n");

    printf("\nEnter previous meter reading: ");
    if (scanf("%u", &previous) != 1 || previous > MAX_READING)
    {
        printf("Invalid previous reading.\n");
        return 1;
    }

    printf("Enter current meter reading: ");
    if (scanf("%u", &current) != 1 || current > MAX_READING)
    {
        printf("Invalid current reading.\n");
        return 1;
    }

    if (current >= previous)
    {
        units = current - previous;
    }
    else if (previous == MAX_READING && current == 0)
    {
        units = ROLLOVER_VALUE - previous + current;
    }
    else
    {
        printf("Invalid reading: meter rollover not detected.\n");
        return 1;
    }

    bill = calculateBill(units);

    printf("\nUnits Consumed: %u\n", units);
    printf("Electricity Bill: Rs. %.2f\n", bill);

    printf("\nFIVE SAMPLE BILLS\n");
    printf("-----------------------------\n");

    {
        unsigned int testUnits[5] = {0, 50, 100, 150, 250};

        for (i = 0; i < 5; i++)
        {
            bill = calculateBill(testUnits[i]);
            printf("Bill %d: %u units = Rs. %.2f\n",
                   i + 1, testUnits[i], bill);

            totalBill += bill;
        }
    }

    printf("-----------------------------\n");
    printf("Total of 5 bills = Rs. %.2f\n", totalBill);

    return 0;
}
