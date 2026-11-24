#include <stdio.h>
#include <limits.h>

/* Function to convert rupees into paise with rounding */
long rupees_to_paise(double rupees)
{
    return (long)(rupees * 100.0 + 0.5);
}

int main(void)
{
    int units = 250;
    int a = 5, b = 2;

    long bill = 16250L;
    float price = 10.50f;
    double amount = 25.75;

    printf("TASK 7 - TYPE CONVERSION AND PRECISION\n\n");

    /* 1. Integer division */
    printf("1. Integer Division:\n");
    printf("5 / 2 = %d\n", a / b);
    printf("5.0 / 2 = %.2f\n", 5.0 / 2);

    /* 2. Explicit type conversion */
    printf("\n2. Explicit Casting:\n");
    printf("(float)5 / 2 = %.2f\n", (float)a / b);
    printf("(int)10.75 = %d\n", (int)10.75);

    /* 3. Implicit conversion */
    printf("\n3. Implicit Conversion:\n");
    printf("Integer + Float = %.2f\n", units + price);
    printf("Integer + Double = %.2f\n", units + amount);

    /* 4. Unsigned and signed conversion */
    printf("\n4. Signed and Unsigned Conversion:\n");
    unsigned int u = 1;
    int s = -2;

    printf("1 + (-2) as unsigned = %u\n", u + s);

    /* 5. Floating-point precision */
    printf("\n5. Floating Point Precision:\n");

    float x = 0.1f;
    float y = 0.2f;

    printf("0.1 + 0.2 = %.10f\n", x + y);

    /* 6. Casting a large long value to int */
    printf("\n6. Large Value Conversion:\n");

    long large = (long)INT_MAX + 1L;
    int small = (int)large;

    printf("INT_MAX = %d\n", INT_MAX);
    printf("Large long value = %ld\n", large);
    printf("After conversion to int = %d\n", small);
    printf("The converted value is implementation-defined.\n");

    /* 7. Rounding fractional rupees to paise */
    printf("\n7. Rounding to Paise:\n");

    double rupees = 162.505;
    long paise = rupees_to_paise(rupees);

    printf("Original amount = Rs %.3f\n", rupees);
    printf("Rounded amount = Rs %ld.%02ld\n",
           paise / 100, paise % 100);

    /* 8. Compare float and integer accumulation */
    printf("\n8. Comparing Float and Integer Bills:\n");

    float float_total = 0.0f;
    long integer_total = 0;

    for (int i = 0; i < 4000; i++)
    {
        float_total += 0.1f;
        integer_total += 10;
    }

    printf("Float total = Rs %.2f\n", float_total);
    printf("Integer total = Rs %ld.%02ld\n",
           integer_total / 100, integer_total % 100);

    return 0;
}
