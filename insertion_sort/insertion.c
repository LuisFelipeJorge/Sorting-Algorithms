#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertion.h"

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

void insertionSort(int array[], int arraySize, long int *numberOfComparisons, long int *numberOfExchanges)
{
  int insertionElement; 
  for (int arrayIndex = 1; arrayIndex < arraySize; arrayIndex++) 
  {
    insertionElement = array[arrayIndex]; 
    *numberOfExchanges += 1;
    int insertionIndex = arrayIndex - 1;
    while (insertionIndex >= 0 && array[insertionIndex] > insertionElement) 
    {
      *numberOfComparisons += 1;
      *numberOfExchanges += 1;
      array[insertionIndex+1] = array[insertionIndex];
      insertionIndex--;
    }
    if (insertionIndex >= 0) { *numberOfComparisons += 1; }
    
    array[insertionIndex + 1] = insertionElement;
    *numberOfExchanges += 1;
  } 
}