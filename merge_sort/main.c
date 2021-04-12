#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "merge.h"

int main(int argc, char const *argv[])
{
  int power; 
  long int arraySize, numberOfComparisons, numberOfExchanges;
  clock_t startTime, endTime;
  double timePassed;

  for (power = 2; power <= 8; power++) 
  { 
    arraySize = 1;
    int iterator = power;
    while (iterator > 0) 
    {
      arraySize = 10*arraySize;
      iterator--;
    }

    long int *array = (long int *) malloc(arraySize*sizeof(long int));
    assert(array != NULL);
    printf("Power = %d\n", power);

    createRandomArray(array, arraySize);
    printf("------------------RECURSIVE MERGE SORT-------------\n");
    numberOfComparisons = 0;
    numberOfExchanges = 0;
    startTime = clock();
    mergeSortRecursive(array, 0, arraySize-1, &numberOfComparisons, &numberOfExchanges);
    endTime = clock();
    timePassed = (double)(endTime - startTime)/CLOCKS_PER_SEC;
    printf("Number of exchanges : %ld\n", numberOfExchanges);
    printf("Number of comparisons : %ld\n",numberOfComparisons);
    printf("Total number of operations : %ld\n", (numberOfComparisons+numberOfExchanges));
    printf("Time passed for sorting (miliseconds): %f\n", timePassed);
    
    free(array);// release the memory
  }
  return 0;
}
