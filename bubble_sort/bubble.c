#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.h"


void swapValues(int *value1, int *value2)
{
  int aux;
  aux = *value1,
  *value1 = *value2;
  *value2 = aux;
}

void createRandomArray(int array[], int arraySize)
{
  srand(time(NULL));
  int arrayIndex;
  for (arrayIndex = 0; arrayIndex < arraySize; arrayIndex++) { 
    array[arrayIndex] = rand() % arraySize;
  }
}

void printArray(int array[], int arraySize)
{
  for (int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
  {
    printf("%d ", array[arrayIndex]);
  }
  printf("\n");
}

void readArrayValues(int array[], int arraySize)
{
  for (int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
  {
    scanf("%d", &array[arrayIndex]);
  }  
}

void bubbleSort(int array[], int arraySize, long int *numberOfComparisons, long int *numberOfExchanges)
{
  for (int arrayIndex = arraySize-1; arrayIndex > 0; arrayIndex--) 
  {
    for (int bubbleIndex = 0; bubbleIndex < arraySize; bubbleIndex++) 
    {
      *numberOfComparisons += 1;
      if (array[bubbleIndex] > array[bubbleIndex+1])
      { 
        *numberOfExchanges += 3;
        swapValues(&array[bubbleIndex], &array[bubbleIndex+1]);
      }
    }
  }
}

void bubbleSortOptimized(int array[], int arraySize, long int *numberOfComparisons, long int *numberOfExchanges)
{
  int lastSortedPositionIndex, lastSwapIndex;

  lastSortedPositionIndex = arraySize - 1;
  while (lastSortedPositionIndex > 0)
  {
    lastSwapIndex = -1;
    for (int arrayIndex = 0; arrayIndex < lastSortedPositionIndex; arrayIndex++)
    { 
      *numberOfComparisons += 1;
      if (array[arrayIndex] > array[arrayIndex+1])
      {
        swapValues(&array[arrayIndex], &array[arrayIndex+1]);
        *numberOfExchanges += 3;
        lastSwapIndex = arrayIndex;
      }    
    }   
    lastSortedPositionIndex = lastSwapIndex;
  }
}
