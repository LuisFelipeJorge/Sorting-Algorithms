#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shell.h"

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


void shell_sort(int *arr, int size, long int *comparisons, long int *exchanges)
{
  int gaps[8] = {701,301,132,57,23,10,4,1}; // best sequence
  int gap; 
  int x;
  int i, j, w;

  for (w = 0; w < 8; w++ ){
    gap = gaps[w];

    for( i = 0; i <= size-gap; i++ ){
      x = arr[i];
      *exchanges += 1;
      j = i - gap;
      while (j >= 0 && arr[j] > x) {
        *comparisons += 1;
        arr[j + gap] = arr[j];
        *exchanges += 1;
        j -= gap;
      }
      if (j >= 0)
      {
        *comparisons += 1;
      }
      arr[j + gap] = x;
      *exchanges += 1;
    }
  }
}
