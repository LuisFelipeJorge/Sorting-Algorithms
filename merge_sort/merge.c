#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "merge.h"

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

void merge_sort_R(long int *arr, long int start, long int end, long int *comparisons, long int *exchanges)
{
  if(end > start)
  {
    long int midle = (start + end)/2;
    merge_sort_R(arr, start, midle, comparisons, exchanges);
    merge_sort_R(arr, midle+1, end, comparisons, exchanges);
    merge(arr, start, midle, midle + 1, end, comparisons, exchanges);
  }
}

void merge(long int *arr, long int start1, long int end1, long int start2, long int end2, long int *comparisons, long int *exchanges)
{
  int len = (end1 - start1 + 1) + (end2 - start2 +1);
  int *copy = (int*)malloc(sizeof(int)*len);
  assert(copy != NULL);
  int idx1 = start1;
  int idx2 = start2;
  int k = 0;
  while (idx1 <=end1 && idx2 <= end2)
  {
    *comparisons += 1;
    if (arr[idx1] <= arr[idx2])
    {
      *exchanges += 1;
      copy[k++]=arr[idx1++];
    }else
    {
      *exchanges += 1;
      copy[k++]=arr[idx2++];
    }   
  }
  while (idx1 <= end1)
  {
    *exchanges += 1;
    copy[k++]=arr[idx1++];
  }        
  while (idx2 <= end2)
  {
    *exchanges += 1;
    copy[k++]=arr[idx2++];
  }     
  for (int i = start1, k = 0; i <= end2; i++, k++)
  {
    *exchanges += 1;
    arr[i] = copy[k];
  }
  free(copy);
}