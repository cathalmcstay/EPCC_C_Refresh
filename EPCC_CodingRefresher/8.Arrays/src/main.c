/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice arrays.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */

int sum2Darray(int arr[5] [3])
{
 int sum = 0;

    for (int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        sum+=arr[i][j];
      }
    }
  return sum;
}

int main(int argc, char* argv[])
{
    // Create an array, statically, of 10 integers.
    int st_array[10];

    /* 
     * Initialise all array elements to their index:
     * Value of first element set to 0.
     * Value of second element set to 1.
     * ...
     * Value of tenth element set to 9.
     */
    for(int i = 0; i<10; i++)
    {
       st_array[i] = i;
    }
     /* 
     * Calculate the sum of all elements in that array by passing this array to
     * a function that will performan the calculation. Store the result in the
     * variable "total".
     */
    int total = 0;
    for(int i = 0; i<10; i++)
    {
       total = total + st_array[i];
    }
    printf("Total = %d.\n", total);

    // Allocate an array of integers, dynamically, containing <total> elements.
    int* dyn_array = (int*) malloc(sizeof(int) * 10);

    for(int i = 0; i<10; i++)
    {
      dyn_array[i] = i;
    }

    // Repeat the sum calculation you did earlier.
    for(int i = 0; i<10; i++)
    {
      total = total + dyn_array[i];
    }
    printf("Total = %d.\n", total);

    // Free the array you just dynamically allocated.
    free(dyn_array);
    // Allocate a 2D array of 5 x 3 elements.
    /* Write a function that receives an array of 5 x 3 elements, and returns
     * the sum of all elements.
     */
    int twod_array[5] [3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12},
    {13, 14, 15}};

    printf("2D Array Sum = %d.\n", sum2Darray(twod_array));

    return EXIT_SUCCESS;
}
