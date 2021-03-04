#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "selection.h"

void swap(int *a, int *b)
{
  int aux;
  aux = *a,
  *a = *b;
  *b = aux;
}

void random_array(int size, int *arr)
{
  srand(time(NULL));
  int i;
  for (i = 0; i < size; i++) { 
    arr[i] = rand() % size;
  }
}

void print_array(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void read_values(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    scanf("%d", arr+i);
  }  
}


void selection_sort(int *arr, int size, long int *comparisons, long int *exchanges)
{
  int i, j;
  int lower_value_idx;

  for ( i = 0; i < size; i++)
  {
    lower_value_idx = i;
    for ( j = i + 1; j < size; j++)
    { 
      *comparisons += 1;
      if (arr[j] < arr[lower_value_idx])
      {
        lower_value_idx = j;
      }      
    }
    if (arr[i] != arr[lower_value_idx])
    {
      *exchanges += 3;  
      swap(&arr[i], &arr[lower_value_idx]);
    }    
  }  
}