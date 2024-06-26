/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice everything you have learned by
 * developing a pagerank application. The source code is decorated with comments
 * and documentations at every step.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>


#define SIZE 5
#define DUMP_FACTOR 0.85
#define MAXIMUM_ITERATIONS 20
/**
 * @brief This function contains the architecture of a pagerank application.
 * @details You have to declare and define the variables and functions used
 * throughout this program. Every milestone is indicated with a documentation
 * block, accompanied with a statement "exit(-1)" which aborts the program.
 * This allowed you to progress step by step: removing the "exit(-1)" once you
 * implemented the corresponding block of code.
 */
void initialise_adjacency_matrix(int matrix[SIZE][SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			if(j >= i)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void print_2D_array(int matrix[SIZE][SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int z = 0; z < SIZE; z++)
		{
		 	printf("%d ", matrix[i][z]);
		}
		printf("\n");
	}
}

void print_ranks(double ranks[SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		printf("%f ", ranks[i]);
	}
	printf("\n");
}

int count_links_from_page(int matrix[SIZE][SIZE], int page)
{
	int count = 0;
	for(int i = 0; i < SIZE; i++)
	{
		if(matrix[page][i] == 1)
		{
			count++;
		}
	}
	return count;
}
	/**
         * new_value = current_value x DUMP_FACTOR + (1.0 - DUMP_FACTOR) / SIZE.
	**/

void normalise_ranks(double ranks[SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		ranks[i] = ranks[i] * DUMP_FACTOR + (1.0 - DUMP_FACTOR) / SIZE;
	}
}

void sum_ranks(double ranks[SIZE])
{
	double sum = 0.0;
	for(int i = 0; i < SIZE; i++)
	{
		sum += ranks[i];
	}
	printf("Sum of all ranks: %f\n", sum);
}

int main(int argc, char* argv[])
{
    /**
     * @brief Use two defines, "SIZE" = 5 and "DUMP_FACTOR" = 0.85.
     * @details SIZE is the number of vertices in the graph (a.k.a: the
     * "graph order"). DUMP_FACTOR is the coefficient controlling the extent to
     * which final ranks are influenced by spreading.
     **/

    /**
     * @brief Create a 2D array of SIZE x SIZE integers, named adjacency_matrix.
     * @details If adjacency_matrix[a][b] = 1, it means that page 'a' has a
     * link to page 'b'. Otherwise, it is 0 and means there is no link from
     * page 'a' to page 'b'.
     **/
    int adjacency_matrix[SIZE][SIZE];
    /**
     * @brief Declare and define the function initialise_adjacency_matrix.
     * @details It receives a 2D array and initialises such that the upper
     * triangle is made of 1s, the rest of 0s.
     * 
     * Example with SIZE = 5
     * 1 1 1 1 1
     * 0 1 1 1 1
     * 0 0 1 1 1
     * 0 0 0 1 1
     * 0 0 0 0 1
     **/
    initialise_adjacency_matrix(adjacency_matrix);

    /**
     * @brief Declare and define the function print_2D_array.
     * @details This function receives a 2D array of SIZE x SIZE elements, and
     * prints it as follows:
     * 
     *                 The right-most
     *                 dimension my_arr[...][X]
     *                 +------------------>
     * The leftmost    | [0][0]  [0][1]  
     * dimension       | [1][0]  [1][1]
     * my_arr[X][...]  | [2][0]  [2][1]
     *                 v
     **/
    print_2D_array(adjacency_matrix);

    /**
     * @brief Create two 1D arrays of SIZE doubles, named "ranks" and
     * "prev_ranks".
     * @details The array "ranks" will contain the final rank of each page,
     * whereas "prev_ranks" will hold ranks from previous iterations that are
     * needed in calculations.
     **/
    double ranks[SIZE];
    double prev_ranks[SIZE];

    /**
     * @brief Initialise array of ranks to 1 / SIZE.
     * @details By default, 1 / SIZE is seen as a division of integers and will
     * result in 0. To make sure that the terms are treated as doubles, we will
     * cast them as follows: 1.0 / (double)SIZE.
     **/
    for(int i = 0; i < SIZE; i++)
    {
	ranks[i] = 1.0 / (double)SIZE;
    }

    /**
     * @brief Declare and define a function that prints an array of SIZE
     * elements, and call it to print the values of the rank array.
     **/
    print_ranks(ranks);

    /**
     * @brief Create a loop for <MAX_ITERATION> iterations.
     **/
    for(int iter = 0; iter < MAXIMUM_ITERATIONS; iter++)
    {
        //////////////////////
        // BEGIN: MAIN LOOP //
        //////////////////////
        /**
         * @brief Copy the values from array <ranks> to array <prev_ranks>.
         **/
        for(int i = 0; i < SIZE; i++)
	{
		prev_ranks[i] = ranks[i];
	}
	print_ranks(prev_ranks);

        /**
         * @brief Reset the values of array <ranks> to 0.
         **/
        for(int y = 0; y < SIZE; y++)
	{
		ranks[y] = 0.0;
	}
	print_ranks(ranks);

        /**
         * @brief Create a loop of <SIZE> iterations.
         * @details We will assume that your iterator is named "i", it will
         * represent the source webpage.
         **/
	for(int i = 0; i < SIZE; i++){
            //////////////////////
            // BEGIN: LOOP I    //
            //////////////////////
            /**
             * @brief Create a loop of <SIZE> iterations.
             * @details We will assume that your iterator is named "j", it will
             * represent the target webpage.
             **/
            for(int j = 0; j < SIZE; j++){
                //////////////////////
                // BEGIN: LOOP J    //
                //////////////////////
                /**
                 * @brief If the webpage "i" has no link to webpage "j", skip
                 * this iteration.
                 **/
                if(adjacency_matrix[i][j] == 0)
		{
			continue;
		}

                /**
                 * @brief Declare and define function count_links_from_page.
                 * @details This function counts the number of links that a
                 * given page has with all other webpages. It receives the 
                 * connectivity matrix, and the source webpage considered. It
                 * returns the number of links obtained.
                **/
		printf("Adj Matrix[i][j]: %d", adjacency_matrix[i][j]);
		 int link_count = count_links_from_page(adjacency_matrix, i);
		 printf("Link Count: %d\n", link_count);
                /**
                 * @brief If the number of links is strictly greater than 0,
                 * add (1 / link_count)th of the source webpage's previous rank
                 * to the current rank of the target webpage.
                 */
                if(link_count > 0)
		{
			ranks[i] += prev_ranks[i] / (double)link_count;
		}
                //////////////////////
                // END: LOOP J      //
                //////////////////////
		}
            ////////////////////
            // END: LOOP I      //
            //////////////////////
	   }
        /**
         * @brief Declare and define the function normalise_ranks.
         * @details This function receives a 1D array of SIZE elements, and 
         * updates the value of every element to:
         * new_value = current_value x DUMP_FACTOR + (1.0 - DUMP_FACTOR) / SIZE.         * 
         **/
        normalise_ranks(ranks);

        /**
         * @brief Calculate the sum of all ranks and prints the value obtained.
         **/
        sum_ranks(ranks);
        
        /**
         * @brief Print all ranks.
         **/
        print_ranks(ranks);

        //////////////////////
        // END: MAIN LOOP   //
        //////////////////////
	}
    return EXIT_SUCCESS;
}
