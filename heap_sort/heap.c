#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "heap.h"

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

void heapfy_recursive(long int *arr, long int parent, long int end, long int *comparisons, long int *exchanges)
{
  long int child = 2*parent+1;
  if ( child <= end)
  {
    if (child + 1 <= end)
    {// has 2 children
      *comparisons += 1;
      if (arr[child+1] > arr[child]) child++; 
    }
    if (arr[child] > arr[parent])
    {
      *exchanges += 3;
      swap(&arr[parent], &arr[child]);
      heapfy_recursive(arr, child, end, comparisons, exchanges);
    }       
  }  
}

void heapfy_iterative(long int *arr, long int parent, long int end, long int *comparisons, long int *exchanges)
{
  while (parent <= end)
  {
    long int child = 2*parent+1;
    if ( child <= end)
    {
      if (child + 1 <= end)
      {// has 2 children
        *comparisons += 1;
        if (arr[child+1] > arr[child]) child++; 
      }
      if (arr[child] > arr[parent])
      {
        *exchanges += 3;
        swap(&arr[parent], &arr[child]);
        parent = child;
      }       
    }
    parent = child;      
  }
}


void heap_sort_r(long int *arr, long int size, long int *comparisons, long int *exchanges)
{
  long int i;
  for ( i = size/2; i >= 0; i--)
  {
    heapfy_recursive(arr, i, size-1, comparisons, exchanges);
  }
  for ( i = size-1; i > 0; i--)
  {
    *exchanges += 3;
    swap(&arr[0], &arr[i]);
    heapfy_recursive(arr, 0, i-1, comparisons, exchanges);  
  }
}

void heap_sort_i(long int *arr, long int size, long int *comparisons, long int *exchanges)
{
  long int i;
  for ( i = size/2; i >= 0; i--)
  {
    heapfy_iterative(arr, i, size-1, comparisons, exchanges);
  }
  for ( i = size-1; i > 0; i--)
  {
    *exchanges += 3;
    swap(&arr[0], &arr[i]);
    heapfy_iterative(arr, 0, i-1, comparisons, exchanges);  
  }
}