#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heap.h"

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

void RecursiveHeapfy(long int *array, long int parentIndex, long int arrayEndIndex, long int *numberOfComparisons, long int *numberOfExchanges)
{
  long int childIndex = 2*parentIndex+1;
  if ( childIndex <= arrayEndIndex)
  {
    if (childIndex + 1 <= arrayEndIndex)
    {
      *numberOfComparisons += 1;
      if (array[childIndex+1] > array[childIndex]) childIndex++; 
    }
    if (array[childIndex] > array[parentIndex])
    {
      *numberOfExchanges += 3;
      swapValues(&array[parentIndex], &array[childIndex]);
      RecursiveHeapfy(array, childIndex, arrayEndIndex, numberOfComparisons, numberOfExchanges);
    }       
  }  
}

void IterariveHeapfy(long int *array, long int parentIndex, long int arrayEndIndex, long int *numberOfComparisons, long int *numberOfExchanges)
{
  while (parentIndex <= arrayEndIndex)
  {
    long int child = 2*parentIndex+1;
    if ( child <= arrayEndIndex)
    {
      if (child + 1 <= arrayEndIndex)
      {
        *numberOfComparisons += 1;
        if (array[child+1] > array[child]) child++; 
      }
      if (array[child] > array[parentIndex])
      {
        *numberOfExchanges += 3;
        swapValues(&array[parentIndex], &array[child]);
        parentIndex = child;
      }       
    }
    parentIndex = child;      
  }
}


void heapSortRecursive(long int *array, long int arraySize, long int *numberOfComparisons, long int *numberOfExchanges)
{
  long int arrayIndex;
  for ( arrayIndex = arraySize/2; arrayIndex >= 0; arrayIndex--)
  {
    RecursiveHeapfy(array, arrayIndex, arraySize-1, numberOfComparisons, numberOfExchanges);
  }
  for ( arrayIndex = arraySize-1; arrayIndex > 0; arrayIndex--)
  {
    *numberOfExchanges += 3;
    swapValues(&array[0], &array[arrayIndex]);
    RecursiveHeapfy(array, 0, arrayIndex-1, numberOfComparisons, numberOfExchanges);  
  }
}

void heapSortIterative(long int *array, long int arraySize, long int *numberOfComparisons, long int *numberOfExchanges)
{
  long int arrayIndex;
  for ( arrayIndex = arraySize/2; arrayIndex >= 0; arrayIndex--)
  {
    IterariveHeapfy(array, arrayIndex, arraySize-1, numberOfComparisons, numberOfExchanges);
  }
  for ( arrayIndex = arraySize-1; arrayIndex > 0; arrayIndex--)
  {
    *numberOfExchanges += 3;
    swapValues(&array[0], &array[arrayIndex]);
    IterariveHeapfy(array, 0, arrayIndex-1, numberOfComparisons, numberOfExchanges);  
  }
}