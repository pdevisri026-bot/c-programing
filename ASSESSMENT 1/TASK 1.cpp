#include <stdio.h>

int main()
{
    char householdNo[30];
    int category;
    long long previousReading, currentReading, units;

    double rate, fixedCharge;
    double energyCharge, totalBill;

    // Input details
    printf("Enter Household Number: ");
    scanf("%29s", householdNo);

    printf("Enter Previous Meter Reading: ");
    scanf("%lld", &previousReading);

    printf("Enter Current Meter Reading: ");
    scanf("%lld", &currentReading);

    printf("\nSelect Category:\n");
    printf("1. Domestic\n");
    printf("2. Commercial\n");
    printf("3. Industrial\n");
    printf("Enter Category: ");
    scanf("%d", &category);

    // Validate meter readings
    if (previousReading < 0 || currentReading < 0 ||
        currentReading < previousReading)
    {
        printf("\nInvalid Meter Readings!\n");
        return 1;
    }

    // Calculate units consumed
    units = currentReading - previousReading;

    // Set tariff based on category
    switch (category)
    {
        case 1:
            rate = 3.00;
            fixedCharge = 50.00;
            break;

        case 2:
            rate = 6.00;
            fixedCharge = 100.00;
            break;

        case 3:
            rate = 8.00;
            fixedCharge = 200.00;
            break;

        default:
            printf("\nInvalid Category!\n");
            return 1;
    }

    // Calculate electricity bill
    energyCharge = units * rate;
    totalBill = energyCharge + fixedCharge;

    // Display bill details
    printf("\n===== ELECTRICITY BILL =====\n");
    printf("Household Number : %s\n", householdNo);
    printf("Previous Reading : %lld\n", previousReading);
    printf("Current Reading  : %lld\n", currentReading);
    printf("Units Consumed   : %lld\n", units);
    printf("Energy Charge    : Rs. %.2f\n", energyCharge);
    printf("Fixed Charge     : Rs. %.2f\n", fixedCharge);
    printf("Total Bill       : Rs. %.2f\n", totalBill);

    return 0;
}
