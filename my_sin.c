/**
 * @file my_sin.c
 * @author  Lior Paz <lior.paz1@mail.huji.ac.il>
 * @version 1.0
 * @date 7 Aug 2018
 *
 * @brief Program calculate sinus value of a number.
 *
 * @section DESCRIPTION
 * Program calculate sinus value of a number.
 * Input  : Real number.
 * Process: Recursive process.
 * Output : Sinus val of the number.
 */

// ------------------------------ includes ------------------------------

#include <stdio.h>
#include <stdlib.h>

// -------------------------- const definitions -------------------------
/**
 * @brief False
 */
#define FALSE 0

/**
 * @brief power a number by 3
 */
#define POWER_BY_3(x) ((x) * (x) * (x))

/**
 * @brief Error message
 */
#define INVALID_INPUT "Not a valid input!"

/**
 * @brief recursion stopping point
 */
#define THRESHOLD 0.01

// ------------------------------ functions -----------------------------
/**
 * @brief calculate sinus
 * @param x input as double
 * @return output as double
 */
double sin(double x)
{
    if (x < THRESHOLD && x > -THRESHOLD)
    {
        return x;
    }
    double temp = sin(x / 3);
    return (3 * temp - 4 * (POWER_BY_3(temp)));
}

/**
 * @brief The main Function.
 * @return 0, to tell the system the execution ended without errors, or 1 if an error has occurred.
 */
int main()
{
    double input;
    if (scanf("%lf", &input) == FALSE)
    {
        fprintf(stderr, INVALID_INPUT);
        return EXIT_FAILURE;
    }
    printf("%lf", sin(input));
    return EXIT_SUCCESS;
}

