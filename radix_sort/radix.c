#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "radix.h"

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
void copy_array(long int *copy, long int *source, long int size)
{
  assert(copy != NULL);
  assert(source != NULL);
  for (int i = 0; i < size; i++)
  {
    copy[i] = source[i];
  }
}

int get_key(long int x, int exp, int base){
  return ((x/exp)%base);
}


void counting_sort(long int *arr, long int size, long int keys, int exp, long int *comparisons, long int *exchanges)
{
  long int i;
  long int *count = calloc(keys, sizeof(long int));
  assert(count != NULL);

  for ( i = 0; i < size; i++)
  {
    count[get_key(arr[i], exp, keys)] += 1;
  }
  long int total = 0;
  for ( i = 0; i < keys; i++)
  {
    long int aux = count[i];
    count[i] = total;
    total += aux;
  }
  long int *out = (long int*)malloc(size*sizeof(long int));
  assert(out != NULL);
  for ( i = 0; i < size; i++)
  {
    *exchanges += 1;
    out[count[get_key(arr[i], exp, keys)]] = arr[i];
    count[get_key(arr[i], exp, keys)]++;
  }
  copy_array(arr, out, size);
  
  free(count);
  free(out);   
}

int get_max(long int n, long int *arr)
{
  long int max = arr[0];
  long int i;
  for(i = 0; i < n; i++)
  {
    if (arr[i] > max) 
    { 
      max = arr[i];
    }
  }
  return max;
}

void radix_sort(long int size, long int *arr, int base, long int *comparisons, long int *exchanges)
{
  long int m = get_max(size,arr);
  for (int exp = 1; m/exp > 0; exp *= base)
  {
    counting_sort(arr, size, base, exp, comparisons, exchanges);
  }
}
