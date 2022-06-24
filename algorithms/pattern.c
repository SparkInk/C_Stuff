/*******************************************************************
 * 
 * Description:
 *             Print a pattern of numbers from 1 to n as showm below
 *                          4 4 4 4 4 4 4   00 01 02 03 04 05 06
                            4 3 3 3 3 3 4   10 11 12 13 14 15 16
                            4 3 2 2 2 3 4   20 21 22 23 24 25 26
                            4 3 2 1 2 3 4   30 31 32 33 34 35 36
                            4 3 2 2 2 3 4   40 41 42 43 44 45 46
                            4 3 3 3 3 3 4   50 51 52 53 54 55 56
                            4 4 4 4 4 4 4   60 61 62 63 64 65 66

 *             The input is a single number from 1 to 1000
 * E.g.:
 *      Input: 3
 *      Output:
 *              3 3 3 3 3
 *              3 2 2 2 3 
 *              3 2 1 2 3
 *              3 2 2 2 3
 *              3 3 3 3 3 
 * Pseudo-code for a prtintin-pattern algorithm
 * The matrix's width: (2n - 1)
 * Approach the middle element 
 *  
 * 
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void iArrayDisp(unsigned int *array, unsigned int size);
void arrayFill(unsigned int *array, unsigned int size , unsigned int filler);
unsigned int arrayReplace(unsigned int *array, unsigned int size, unsigned int row, unsigned int column, unsigned int new);
unsigned int *arrayPattern(unsigned int *array, unsigned int size, unsigned int filler);

int main() {
    unsigned int filler;
    unsigned int size;

    // create an array
    printf("Array size\n");
    scanf("%d", &filler);

    // compute the size of the array
    size = 2 * filler - 1;

    // create a doulbe array
    unsigned int *array = (int*)calloc((size * size), sizeof(int));

    // fill in the array with numbers    
    arrayFill(array, size, filler);

    printf("Array before: \n");
    iArrayDisp(array, size);
    
    // replace elements in the array
    array = arrayPattern(array, size, filler);

    printf("Array after: \n");
    iArrayDisp(array, size);

    free(array);
    
    return 0;
}

/*******************************************************************
 * Name: iArrayDisp
 * 
 * Description: prints out integers from a passed 2D-array
 * 
 * Input: *array    -   an array to be displayed 
 *         size     -   the size of the array
 * Return:
 * 
 * Author: Iasha Umrikhin
 * 
 * Date created: 03.06.2022
 * Date modified: 23.06.2022
 * *****************************************************************/

void iArrayDisp(unsigned int *array, unsigned int size) {
    
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            printf("%d ", *(array + row * size + column));  // 3x3 array has rows: 0, 3, 6   ->  0 * 3, 1 * 3, 2 * 3
                                                            // it is just a long line [3 3 3  3 3 3  3 3 3]
                                                            //                 indexes 0 1 2  3 4 5  6 7 8
        }
        printf("\n");   // new line
    }
}

/*******************************************************************
 * Name: arrayFill
 * 
 * Description: fill a 2D-array with a passed value
 * 
 * Input: *array    -   an array to be displayed 
 *         size     -   the size of the array
 *         filler   -   a number to fill the array with
 * 
 * Return: None
 * 
 * Author: Iasha Umrikhin
 * 
 * Date created: 03.06.2022
 * Date modified: 23.06.2022
 * *****************************************************************/

void arrayFill(unsigned int *array, unsigned int size , unsigned int filler) {
    
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            *(array + row * size + column) = filler;        // 3x3 array has rows: 0, 3, 6   ->  0 * 3, 1 * 3, 2 * 3
                                                            // it is just a long line [3 3 3  3 3 3  3 3 3]
                                                            //                 indexes 0 1 2  3 4 5  6 7 8
        }
    }
}

/*******************************************************************
 * Name: arrayReplace
 * 
 * Description: replaces an old values with a new value
 *              in an array
 * 
 * Input: *array     -   the input array
 *         size      -   the size of the array
 *         row       -   the row of an element to be replaced
 *         column    -   the columns of an elemnt to be replaced
 *         old       -   the old value    <-  do we need this? 
 *         new       -   the new value
 * 
 * Author: Iasha Umrikhin
 * 
 * Date created: 23.06.2022
 * Date modified: 23.06.2022
 * *****************************************************************/
unsigned int arrayReplace(unsigned int *array, unsigned int size, unsigned int row, unsigned int column, unsigned int new) {

    *(array + row * size + column) = new;

    return *array;
}
/*******************************************************************
 * Name: arrayPattern
 * 
 * Description: returns an array with a numberwise-gradient pattern
 * Example: intitial array: 3 3 3 3 3     pattern:  3 3 3 3 3
 *                          3 3 3 3 3               3 2 2 2 3
 *                          3 3 3 3 3   ->          3 2 1 2 3
 *                          3 3 3 3 3               3 2 2 2 3
 *                          3 3 3 3 3               3 3 3 3 3
 * 
 * Input: *array     -   the input array
 *         size      -   the size of the array
 *         filler   -   a number to fill the array with
 * 
 * Author: Iasha Umrikhin
 * 
 * Date created: 23.06.2022
 * Date modified: 23.06.2022
 * *****************************************************************/
unsigned int *arrayPattern(unsigned int *array, unsigned int size, unsigned int filler) {

    unsigned int reducer = 1;   // to shrinken the main array

    for (int gradient = (filler - 1); gradient >= 1; gradient--) {   // loop for gradients to replace old values
        // double loop to go through each element in the array
        for (int row = reducer; row < (size - reducer); row++) {
            for (int column = reducer; column < (size - reducer); column++) {
                *(array + row * size + column) = gradient;
            }
        }
        reducer++;
    }

    return array;
}