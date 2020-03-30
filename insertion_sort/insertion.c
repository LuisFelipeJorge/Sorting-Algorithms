#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

// Declaring the Functions
// ----------------------------
void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]);// function to print the array in columns
void insertionSort(long int n, long int a[]);//function that contains the algorithm

int main(int argc, char const *argv[]) {

  int k;
  long int n;// n represents the size of the array
  for (k = 2; k <=5 ; k++) {
    n =1;
    int i = k;
    // n = 10^k
    while (i > 0) {
      n = 10*n;
      i--;
    }

    long int *a = (long int *) malloc(n*sizeof(long int));// allocating the memory for the array
    printf("K = %d\n", k  );
    random_array(n,a);
    printf("------------------INSERTION SORT---------------------\n");
    insertionSort(n,a);
    free(a);
  }
  getchar();
  return 0;
}

// Functions
//-----------------------------

void random_array(long int n, long int a[]){
  // n is the number of elements of the array
  srand(time(NULL));
  long int i;
  for (i = 0; i < n; i++) { // loop to fill the array
    a[i] = rand() % n;
    //this generates a set of random numbers in the range 0 to n
  }
}

void print_array(long int n, long int a[]){
  printf("Printing the array : \n" );
  long int i;
  int count = 0; // to count the number of columns in each row
  for ( i = 0; i < n; i++) {
    printf("a[%ld] = %ld ",i,a[i] );
    count += 1;
    if (count == 10){ // print the array in 10 columns
      printf("\n"); // new row
      count = 0; // return to count
    }
  }
}

void insertionSort(long int n, long int a[]) {
  long int movementsCounter,comparisonsCounter;
  movementsCounter = 0;
  comparisonsCounter = 0;
  clock_t start,end; //variables to measure the time taken by the algorithm
  double timeUsed; // variable to store the value in seconds

  start = clock();
  long int m; // variable to store the value that will be inserted
  long int i,j; // variables to auxiliate in the loops
  for ( i = 1; i < n; i++) {
    m = a[i]; // we assume in the fist movement that the first element is sorted, then
    // m will be the element to be inserted, so it first value will be the a[1]
    movementsCounter++;
    j = i - 1;// we will compare the current element with the element on its left
    while (j >= 0 && a[j] > m) {
      comparisonsCounter++;
      a[j+1] = a[j]; // swap
      movementsCounter++;
      j--; //with this update we start to check the element to be inserted with the others on the left part of the array
    }
    a[j+1] = m;//placing the element in the right position
    movementsCounter++;
  }
  end = clock();
  timeUsed = ((double)(end - start))/ CLOCKS_PER_SEC;

  printf("number of movements : %ld \n",movementsCounter );
  printf("number of comparisons : %ld \n",comparisonsCounter );
  printf("Time passed for sorting : %f \n", timeUsed );
}
