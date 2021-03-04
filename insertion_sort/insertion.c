#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertion.h"

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

void insertion_sort(int *arr, int size, long int *comparisons, long int *exchanges)
{
  int x; 
  int i,j; 
  for ( i = 1; i < size; i++) 
  {
    x = arr[i]; 
    *exchanges += 1;
    j = i - 1;
    while (j >= 0 && arr[j] > x) 
    {
      *comparisons += 1;
      arr[j+1] = arr[j];
      *exchanges += 1;
      j--;
    }
    if (j>=0)
    {
      *comparisons += 1;
    }
    
    arr[j+1] = x;
    *exchanges += 1;
  } 
}