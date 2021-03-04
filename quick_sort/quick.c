#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "quick.h"

void swap(long int *a, long int *b)
{
  long int aux;
  aux = *a,
  *a = *b;
  *b = aux;
}

void print_array(long int *arr, long int size)
{
  for (long int i = 0; i < size; i++)
  {
    printf("%ld ", arr[i]);
  }
  printf("\n");
}

void random_array(long int size, long int *arr)
{
  srand(time(NULL));
  long int i;
  for (i = 0; i < size; i++) { 
    arr[i] = rand() % size;
  }
}

void read_values(long int *arr, long int size)
{
  for (long int i = 0; i < size; i++)
  {
    scanf("%ld", arr+i);
  }  
}

void quick_sort(long int *arr, long int start, long int end, long int *comparisons, long int *exchanges)
{
  if (start >= end) return;
  long int middle = (start + end)/2;
  long int pivot = arr[middle];
  long int i = start;
  long int j = end;
  while (1)
  {
    while(arr[i] < pivot)
    {
      *comparisons += 1;
      i++;
    }// arr[i] >= pivot
    while(arr[j] > pivot)
    {
      *comparisons += 1;
      j--;
    }// arr[j] <= pivot

    if (i >= j) break; 
    *exchanges += 3;
    swap(&arr[i], &arr[j]);
    i++;j--;
  }  
  quick_sort(arr, start, j, comparisons, exchanges);
  quick_sort(arr, j+1, end, comparisons, exchanges);
}