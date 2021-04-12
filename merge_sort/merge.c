#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "merge.h"

void swapValues(long int *value1, long int *value2)
{
  long int aux;
  aux = *value1,
  *value1 = *value2;
  *value2 = aux;
}

void createRandomArray(long int array[], long int arraySize)
{
  srand(time(NULL));
  long int arrayIndex;
  for (arrayIndex = 0; arrayIndex < arraySize; arrayIndex++) { 
    array[arrayIndex] = rand() % arraySize;
  }
}

void printArray(long int array[], long int arraySize)
{
  for (long int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
  {
    printf("%ld ", array[arrayIndex]);
  }
  printf("\n");
}

void readArrayValues(long int array[], long int arraySize)
{
  for (long int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
  {
    scanf("%ld", &array[arrayIndex]);
  }  
}

void copyArray(long int destination[], long int source[], long int startIndex, long int endIndex) {
  for (long int destinationIndex = startIndex, sourceIndex=0; destinationIndex <= endIndex; destinationIndex++, sourceIndex++)
    destination[destinationIndex] = source[sourceIndex];  
}

void mergeSortRecursive(long int array[],
  long int startIndex, 
  long int endIndex, 
  long int *numberOfComparisons, 
  long int *numberOfExchanges)
{
  if(endIndex > startIndex)
  {
    long int midle = (startIndex + endIndex)/2;
    mergeSortRecursive(array, startIndex, midle, numberOfComparisons, numberOfExchanges);
    mergeSortRecursive(array, midle+1, endIndex, numberOfComparisons, numberOfExchanges);
    merge(array, startIndex, midle, midle + 1, endIndex, numberOfComparisons, numberOfExchanges);
  }
}

void merge(long int array[], 
  long int leftStartIndex, 
  long int leftEndIndex, 
  long int rightStartIndex, 
  long int rightEndIndex, 
  long int *numberOfComparisons, 
  long int *numberOfExchanges)
{
  long int subArraySize = (leftEndIndex - leftStartIndex + 1) + (rightEndIndex - rightStartIndex +1);
  long int *arrayCopy = (long int*)malloc(sizeof(long int)*subArraySize);
  assert(arrayCopy != NULL);
  long int idx1 = leftStartIndex;
  long int idx2 = rightStartIndex;
  long int copyIndex = 0;
  while (idx1 <=leftEndIndex && idx2 <= rightEndIndex)
  {
    numberOfComparisons += 1;
    if (array[idx1] <= array[idx2])
    {
      *numberOfExchanges += 1;
      arrayCopy[copyIndex++]=array[idx1++];
    }else
    {
      *numberOfExchanges += 1;
      arrayCopy[copyIndex++]=array[idx2++];
    }   
  }
  while (idx1 <= leftEndIndex)
  {
    *numberOfExchanges += 1;
    arrayCopy[copyIndex++]=array[idx1++];
  }        
  while (idx2 <= rightEndIndex)
  {
    *numberOfExchanges += 1;
    arrayCopy[copyIndex++]=array[idx2++];
  }     

  copyArray(array, arrayCopy,leftStartIndex , rightEndIndex);
  free(arrayCopy);
}