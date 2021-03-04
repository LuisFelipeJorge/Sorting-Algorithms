#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.h"

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


void bubble_sort(int *arr, int size, long int *comparisons, long int *exchanges)
{
  int i,j;

  for (i = size-1; i > 0; i--) 
  {
    for ( j = 0; j < size; j++) 
    {
      *comparisons += 1;
      if (arr[j] > arr[j+1])
      { 
        *exchanges += 3;
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}


void bubble_sort_Op(int* arr, int size, long int *comparisons, long int *exchanges)
{
  int i,j;
  int last_swap;

  j = size - 1;
  while (j > 0)
  {
    last_swap = -1;
    for ( i = 0; i < j; i++)
    { 
      *comparisons += 1;
      if (arr[i] > arr[i+1])
      {
        swap(&arr[i], &arr[i+1]);
        *exchanges += 3;
        last_swap = i;
      }    
    }   
    j = last_swap;
  }
}
