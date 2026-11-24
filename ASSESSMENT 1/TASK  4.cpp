#include <stdio.h>

/* Macro to convert rupees into paise */
#define RUPEES_TO_PAISE(x) ((x) * 100)

/* Safe macro to find square */
#define SQUARE(x) ((x) * (x))

/* Safe macro to find maximum */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/* Static inline function for square */
static inline int square_function(int x)
{
    return x * x;
}

/* Static inline function for maximum */
static inline int max_function(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 5;
    int b = 10;
    int i = 4;

    printf("Rupees to Paise: %d\n", RUPEES_TO_PAISE(50));

    printf("Square of a: %d\n", SQUARE(a + 1));

    printf("Maximum value: %d\n", MAX(a, b));

    printf("Square using inline function: %d\n",
           square_function(a));

    printf("Maximum using inline function: %d\n",
           max_function(a, b));

    printf("MAX with increment: %d\n", MAX(i++, b));
    printf("Value of i: %d\n", i);

    return 0;
}
