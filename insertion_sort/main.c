#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "insertion.h"

int main(int argc, char const *argv[])
{
  int power, arraySize; 
  long int numberOfComparisons, numberOfExchanges;
  clock_t startTime, endTime;
  double timePassed;

  for (power = 2; power <= 5; power++) 
  { 
    arraySize = 1;
    int iterator = power;
    while (iterator > 0) 
    {
      arraySize = 10*arraySize;
      iterator--;
    }

    int *array = (int *) malloc(arraySize*sizeof(int));
    assert(array != NULL);
    printf("Power = %d\n", power);

    createRandomArray(array, arraySize);
    printf("------------------INSERTION SORT----------------------\n");
    numberOfComparisons = 0;
    numberOfExchanges = 0;
    startTime = clock();
    insertionSort(array, arraySize, &numberOfComparisons, &numberOfExchanges);
    endTime = clock();
    timePassed = (double)(endTime - startTime)/CLOCKS_PER_SEC;
    printf("Number of exchanges : %ld\n", numberOfExchanges);
    printf("Number of comparisons : %ld\n",numberOfComparisons);
    printf("Total number of operations : %ld\n", (numberOfComparisons+numberOfExchanges));
    printf("Time passed for sorting (miliseconds): %f\n", timePassed);

    free(array);
  }
  return 0;
}
