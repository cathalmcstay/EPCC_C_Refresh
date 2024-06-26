/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice modular compilation.
 * @details This exercise makes you create two distinct pairs of header / source
 * files, by moving one function from this file main.c to each. The objective is
 * for you to then compile each source file independently to its own object
 * file, before linking all three object files to a single executable.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>
#include "multiply_numbers.h"
#include "addition.h"

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */
int main(int argc, char* argv[])
{    
    // Move add_number to its own set of files (header / source file)
    int sum = add_numbers(123, 456);
    printf("The sum of 123 and 456 is %d.\n", sum);

    // Move multiply_numbers to its own set of files (header / source file)
    int multiply = multiply_numbers(123, 456);
    printf("The product of 123 and 456 is %d.\n", multiply);

    return EXIT_SUCCESS;
}
