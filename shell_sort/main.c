#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shell.h"

int main(int argc, char const *argv[])
{
    int k; // the input will be of size 10 raised to the power k 
  int size; 
  long int comparisons, exchanges;

  clock_t start,end;
  double time_passed;

  for (k = 2; k <= 7; k++) 
  { 
    size = 1;
    int i = k;
    while (i > 0) 
    {
      size = 10*size;
      i--;
    }

    int *a = (int *) malloc(size*sizeof(int)); 
    printf("K = %d\n", k);

    random_array(size, a);
    printf("------------------SHELL SORT----------------------\n");
    comparisons = 0;
    exchanges = 0;
    start = clock();
    shell_sort(a, size, &comparisons, &exchanges);
    end = clock();
    time_passed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Number of exchanges : %ld\n", exchanges);
    printf("Number of comparisons : %ld\n",comparisons);
    printf("Total number of operations : %ld\n", (comparisons+exchanges));
    printf("Time passed for sorting (miliseconds): %f\n", time_passed);

    free(a);// releasing the allocated memory
  }
  return 0;
}
