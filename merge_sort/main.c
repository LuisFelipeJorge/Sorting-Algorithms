#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "merge.h"

int main(int argc, char const *argv[])
{
  int k; // the input will be of size 10 raised to the power k 
  long int size; 
  long int comparisons, exchanges;


  clock_t start,end;
  double time_passed;

  for (k = 2; k <= 8; k++) 
  { 
    size = 1;
    int i = k;
    while (i > 0) 
    {
      size = 10*size;
      i--;
    }

    long int *a = (long int *) malloc(size*sizeof(long int));
    assert(a != NULL);
    printf("K = %d\n", k);

    random_array(size, a);
    printf("------------------RECURSIVE MERGE SORT-------------\n");
    comparisons = 0;
    exchanges = 0;
    start = clock();
    merge_sort_R(a, 0, size-1, &comparisons, &exchanges);
    end = clock();
    time_passed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Number of exchanges : %ld\n", exchanges);
    printf("Number of comparisons : %ld\n",comparisons);
    printf("Total number of operations : %ld\n", (comparisons+exchanges));
    printf("Time passed for sorting (miliseconds): %f\n", time_passed);
    
    free(a);// release the memory
  }
  return 0;
}
